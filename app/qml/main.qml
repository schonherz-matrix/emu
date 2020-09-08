import QtQuick 2.15
import QtQuick.Window 2.15

import hu.bme.kszk.SchonherzItem 1.0

Window {
    width: schonherz.width
    height: schonherz.height
    maximumWidth: schonherz.width
    maximumHeight: schonherz.height
    visible: true
    title: "Emu"

    SchonherzItem {
        id: schonherz

        currentFrame: MuebReceiver.frame
    }
}
