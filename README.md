# qmk-config

Related:

- <https://github.com/lttb/zmk-config>

Keyboards:

```sh
# Sofle v1 choc (Mechboards UK)
# @see https://mechboards.co.uk/products/sofle-choc-hotswap-kit-pre-build
qmk compile -kb sofle_choc -km lttb

# Planck EZ (ZSA)
# @see https://blog.zsa.io/2307-goodbye-planck-ez/
qmk compile -kb planck/ez -km lttb

# Redox Wireless (Falbatech)
# @see https://falbatech.click/products/ReDOX-Wireless-Fully-Assembled-Custom-Mechanical-Keyboard-p633260056
qmk compile -kb redox_w -km lttb

# Keebio Quefrency Rev5
# @see https://keeb.io/products/quefrency-rev-5-pcbs-hotswap-65-65xt-split-staggered-keyboard
qmk compile -kb keebio/quefrency/rev5 -km lttb

# Keebio Cepstrum
# @see https://keeb.io/products/cepstrum-choc-low-profile-65-65xt-split-staggered-keyboard
qmk compile -kb keebio/cepstrum/rev1 -km lttb

# Allium58 (beekeeb)
# @see https://github.com/beekeeb/allium58
# @see https://shop.beekeeb.com/product/allium58-glp-wired-kit/
qmk compile -kb lily58/rev1 -km lttb -e CONVERT_TO=promicro_rp2040

# Keychron Q15 Pro
QMK_HOME="~/path/to/Keychron/qmk_firmware" qmk compile -kb keychron/q15_max/ansi_encoder -km lttb

# Corne Max
# @see https://github.com/MechboardsLTD/qmk_firmware/tree/corne_max/keyboards/mechboards/crkbd/rp2g
qmk compile -kb mechboards/crkbd/rp2g -km lttb
```
