- [x] Use media keys for volume, as KB_VOL doesn't work on Windows 11
- [x] clean NUM layer left side
- [x] Add another 0 next to the 1 key
- [x](draw) replace mouse layer with static yaml in keymap drawing process
- PrintScreen: Full screen / partial separate bindings for macOS and other

## *(Done)* Dealing with different shortcuts between Mac vs Linux

Enable automatically adapting to macOS, and add to shortcuts layer if the combo is not in EXt or shortcuts layer yet:

### Common shortcuts

- find: C-f > G-f
- copy: C-c > G-c
- copy plaintext: S-C-c > G-c
- paste: C-v > G-v
- paste plaintext: S-C-v > G-v (although the original still works in kitty)
- cut: C-x > G-x
- jump word outside vim/terminal: C-arrows > A-arrows  (lower priority)

### OS nav

- next OS window: A-Tab > G-Tab
- previous OS window: S-A-Tab > S-G-Tab

### Browser shortcuts

- close tab: C-w > G-w
- open tab: C-t > G-t
- re-open closed tab: S-C-t > S-G-t (Edge does not allow remapping)

Note: kitty shortcuts are the same across macOS and Linux
