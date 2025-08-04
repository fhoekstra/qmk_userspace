qmk c2json -kb bastardkb/tbkmini/v1/elitec -km fhoekstra >km.json
keymap parse -c 10 -q km.json >km.yaml
keymap draw km.yaml >km.svg
