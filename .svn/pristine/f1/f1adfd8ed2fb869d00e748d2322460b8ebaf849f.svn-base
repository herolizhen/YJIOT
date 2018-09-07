#
# Copyright 2016, MXCHIP Corporation
# All Rights Reserved.
#

Sodium_DIR := src
INCLUDE_PATH_PREFIX := ../

# chacha20poly1305
$(NAME)_SOURCES += 	\
					$(Sodium_DIR)/crypto_aead/chacha20poly1305/sodium/aead_chacha20poly1305.c

# Onetimeauth, poly1305                  
$(NAME)_SOURCES += 	\
                    $(Sodium_DIR)/crypto_onetimeauth/crypto_onetimeauth.c \
                    $(Sodium_DIR)/crypto_onetimeauth/poly1305/onetimeauth_poly1305_api.c \
                    $(Sodium_DIR)/crypto_onetimeauth/poly1305/onetimeauth_poly1305.c \
                    $(Sodium_DIR)/crypto_onetimeauth/poly1305/donna/auth_poly1305_donna.c \
                    $(Sodium_DIR)/crypto_onetimeauth/poly1305/donna/verify_poly1305_donna.c
                    
# sign
$(NAME)_SOURCES += 	\
					$(Sodium_DIR)/crypto_sign/crypto_sign.c \
					$(Sodium_DIR)/crypto_sign/ed25519/sign_ed25519_api.c \
					$(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_0.c \
					$(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_1.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_add.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_neg.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_cmov.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_copy.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_frombytes.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_invert.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_isnegative.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_isnonzero.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_mul.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_pow22523.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_sq.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_sq2.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_sub.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/fe_tobytes.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_add.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_double_scalarmult.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_frombytes.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_madd.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_msub.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p1p1_to_p2.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p1p1_to_p3.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p2_0.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p2_dbl.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p3_0.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p3_dbl.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p3_to_cached.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p3_to_p2.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_p3_tobytes.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_precomp_0.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_scalarmult_base.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_sub.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/ge_tobytes.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/sc_muladd.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/sc_reduce.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/keypair.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/open.c \
                    $(Sodium_DIR)/crypto_sign/ed25519/ref10/sign.c

#verify            
$(NAME)_SOURCES += 	\
                    $(Sodium_DIR)/crypto_verify/16/verify_16_api.c \
                    $(Sodium_DIR)/crypto_verify/16/ref/verify_16.c \
                    $(Sodium_DIR)/crypto_verify/32/verify_32_api.c \
                    $(Sodium_DIR)/crypto_verify/32/ref/verify_32.c
                    
#stream            
$(NAME)_SOURCES += 	\
                    $(Sodium_DIR)/crypto_stream/crypto_stream.c \
                    $(Sodium_DIR)/crypto_stream/chacha20/stream_chacha20_api.c \
                    $(Sodium_DIR)/crypto_stream/chacha20/ref/stream_chacha20_ref.c
                    
#randombytes            
$(NAME)_SOURCES += 	\
                    $(Sodium_DIR)/randombytes/randombytes.c \
                    $(Sodium_DIR)/randombytes/sysrandom/randombytes_sysrandom.c
	

#Sodium            
$(NAME)_SOURCES += 	\
                    $(Sodium_DIR)/sodium/utils.c
                   
                   


$(NAME)_INCLUDES := inc/sodium

