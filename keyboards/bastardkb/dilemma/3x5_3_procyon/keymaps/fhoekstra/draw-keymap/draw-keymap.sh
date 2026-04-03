qmk c2json -kb bastardkb/dilemma/3x5_3_procyon -km fhoekstra >km.json
sed -i \
    -e 's|bastardkb/dilemma/3x5_3_procyon|bastardkb/dilemma/3x5_3|g' \
    km.json
keymap -c keymap-config.yaml parse -c 10 -q km.json >km.yaml
# replace the layer names
sed -i \
    -e 's/L0/BASE/g' \
    -e 's/L1/EXT/g' \
    -e 's/L2/SYM/g' \
    -e 's/L3/FUNC (EXT+SYM)/g' \
    -e 's/L4/NUM/g' \
    -e 's/L5/SHRT/g' \
    -e 's/L6/MOUSE/g' \
    -e 's/LT(LAYER POINTER,Z)/Z (MOUSE)/g' \
    -e 's/AltGr 5/€/g' \
    km.yaml
yq eval-all 'select(filename == "km.yaml") * select(filename == "mouse-layer.yaml")' km.yaml mouse-layer.yaml >merged.yaml
keymap draw <(cat merged.yaml combos.yaml) >km.svg
