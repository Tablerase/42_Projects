# 42 Wifi 

https://meta.intra.42.fr/articles/wifi-42paris-general-informations

## Config file

```bash
# <essid>.8021x
sudo nvim /var/lib/iwd/42Paris.8021x
# Content:
# TTLS: https://unix.stackexchange.com/questions/668151/802-1x-wireless-connection-using-iwctl
# (doesnt work at 42) PEAP: https://bbs.archlinux.org/viewtopic.php?id=259050
[Security]
EAP-Method=TTLS
EAP-Identity=login42
EAP-TTLS-Phase2-Method=Tunneled-PAP
EAP-TTLS-Phase2-Identity=login42
EAP-TTLS-Phase2-Password=yourPassword

[Settings]
AutoConnect=true
```

Go inside `iwctl` and do the following instructions:

```bash
device list            # to find your wireless device (e.g. wlan0)
station wlan0 scan
station wlan0 get-networks
station wlan0 connect 42Paris
```
