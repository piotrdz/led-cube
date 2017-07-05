SDCC=sdcc -mmcs51 --model-small --out-fmt-ihx --code-size 0x2000 \
-DUSE_stringLength -DUSE_compareStrings -DUSE_compareSubstrings \
-DUSE_hexToString -DUSE_stringToHex

SREC_CAT=srec_cat -DSW -line-length=40 --address-length=2

all: led.hex

string_utils.rel: string_utils.c string_utils.h
	$(SDCC) -c string_utils.c

conv_utils.rel: conv_utils.c conv_utils.h
	$(SDCC) -c conv_utils.c

led.ihx: string_utils.rel conv_utils.rel led.c
	$(SDCC) led.c string_utils.rel conv_utils.rel

led.hex: led.ihx
	$(SREC_CAT) led.ihx -intel -o led.hex -intel

clean:
	for EXT in asm hex ihx lk lnk lst map mem rel rst sym; do \
	  rm -f *.$$EXT; \
	done

.PHONY: all clean
