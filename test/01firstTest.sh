#!/bin/bash
vba $1&
sleep 2

WID=`xdotool search --name "VisualBoyAdvance" | head -n 1`

xdotool windowfocus $WID

# xmacrorec2
echo "KeyStrPress Right
KeyStrRelease Right
KeyStrPress z
KeyStrRelease z
KeyStrPress BackSpace
KeyStrPress BackSpace
KeyStrPress Right
KeyStrRelease Right
KeyStrRelease BackSpace
KeyStrPress z
KeyStrRelease z
KeyStrPress BackSpace
KeyStrPress BackSpace
KeyStrPress BackSpace
KeyStrPress BackSpace
KeyStrPress Right
KeyStrRelease Right
KeyStrRelease BackSpace
KeyStrPress z
KeyStrRelease z
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress z
KeyStrPress Up
KeyStrRelease Up
KeyStrRelease z
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress z
KeyStrPress Down
KeyStrRelease Down
KeyStrRelease z
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress Down
KeyStrRelease Down
KeyStrPress z
KeyStrPress Up
KeyStrRelease Up
KeyStrRelease z
KeyStrPress Return
KeyStrRelease Return"  | xmacroplay -d 100
sleep 4
echo "KeyStrPress Return
KeyStrRelease Return"  | xmacroplay -d 100

killall vba
