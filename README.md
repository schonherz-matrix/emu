# emu

Emulator for Schönherz Mátrix

![This emulator represent the dormitory](emu.png)

## Usage

### Old libmueb(v2/Qt 5)

When testing add an IP address to your loopback interface from the 10.6.0.0/16 subnet(If you're not already in the
subnet).

Linux/Unix:

```bash
sudo ip a a 10.6.0.1/16 dev lo
```

Windows:

Install a loopback adapter then set the correct IP address.

### New libmueb(v4/Qt 6)

See https://github.com/schonherz-matrix/libmueb/blob/main/README.md#Config
