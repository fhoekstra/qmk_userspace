qmk c2json -kb bastardkb/tbkmini/v1/elitec -km fhoekstra >km.json
keymap -c keymap-config.yaml parse -c 10 -q km.json >km.yaml
# replace the layer names
sed -i \
    -e 's/L0/BASE/g' \
    -e 's/L1/NUM/g' \
    -e 's/L2/SYM/g' \
    -e 's/L3/EXTRA (NUM+SYM)/g'\
    -e 's/AltGr 5/€/g' \
    km.yaml
keymap draw <(cat km.yaml combos.yaml) >km.svg
