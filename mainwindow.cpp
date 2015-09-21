#include "mainwindow.h"
#include <QMainWindow>
#include <QColorDialog>

#include <cstdlib>

MainWindow::MainWindow(QWidget *parent): QMainWindow{parent} {
	
	/* Initalize members */
	frameProcessor = std::unique_ptr<FrameProcessor>{new FrameProcessor{}};
	gridDrawer = std::unique_ptr<GridDrawer>{new GridDrawer{this, frameProcessor->getEmuConfiguration().width, frameProcessor->getEmuConfiguration().height, 20}};
	
	/* Setting geometry */
	setGeometry(250, 250, gridDrawer->sizeHint().width(), gridDrawer->sizeHint().height());

	/* Setting ColorDialog as central widget */
    setCentralWidget(gridDrawer.get());

	/* View -> Controller signals */
	qRegisterMetaType<Frame>("Frame");
    connect(frameProcessor.get(), &FrameProcessor::newFrame, gridDrawer.get(), &GridDrawer::setFrame);
    
    for (int i = 0; i < 100; i++) {
		Frame frame_;
		frame_.pixels = Array2D<RGB>{frameProcessor->getEmuConfiguration().width, frameProcessor->getEmuConfiguration().height};
		for (int x = 0; x < frame_.pixels.getWidth(); x++) {
			for (int y = 0; y < frame_.pixels.getHeight(); y++) {
				frame_.pixels(x,y) = RGB{rand()%256, rand()%256, rand()%256};
			}
		}
		frameProcessor->sendFrame(frame_, frame_);
	}
}

MainWindow::~MainWindow(){

}
