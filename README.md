Mátrix emulátor
===============

# Fordítás

 * A ```git submodule update --init mueb``` paranccsal töltsük le a _mueb_ alkarton tartalmát. 
 * QtCreatorban nyissuk meg a _mueb_ projektet
 * A projekt beállításai alatt kapcsoljuk ki a _'Shadow build'_ lehetőséget
 * Nyisukk meg most az _'Emu'_ mappában található projekt fájlt, majd fordítsuk le

# Futtatás
 * Vegyük fel a gépünk _loopback_ interfészére a 10.6.0.0/16-os hálóból egy tetszőleges nem broadcast címet
 * Kattintsunk QtCreatorban a futtatás gombra

# Hasznos parancsok

```bash
    sudo ip a a 10.6.23.45/16 dev lo
```
