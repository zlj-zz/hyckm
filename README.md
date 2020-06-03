# HYCKM

Help you to change the keyboard mapping of Linux system more easily.

## Install

```shell
git clone --depth=1 https://github.com/zlj-zz/hyckm.git ~/.hyckm
make install
```

## Use

Command line type `hyckm` to start. Then you can see a simple menu, like :

```
       ==================
       = WELCOME to USE =
       ==================

What keymap you want to change ? If want to map 'Escape' to 'Caps_Lock', like (Escape Caps_Lock).
Support a-z(lower case) 0-9 F1-F12

......
```

Just follow the prompts.

## Update

```shell
cd ~/.hyckm
git pull
```

## Uninstall

```shell
make uninstall
rm ~/.hyckm
```


