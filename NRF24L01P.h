/**
 * SPI commands
 */

#define make_R_REGISTER(reg) (reg & 0x1F)
#define make_W_REGISTER(reg) (0x20 | (reg & 0x1F))
#define make_W_ACK_PAYLOAD(pipe) (0xA8 | (pipe & 0x07))

#define R_RX_PAYLOAD       0x61
#define W_TX_PAYLOAD       0xA0
#define FLUSH_TX           0xE1
#define FLUSH_RX           0xE2
#define REUSE_TX_PL        0xE3
#define R_RX_PL_WID        0x60
#define W_TX_PAYLOAD_NOACK 0xB0
#define NOP                0x00

/**
 * Register mappings and utility macros for the NRF24L01+
 */

#define CONFIG 0x00
#define MASK_RX_DR  6
#define MASK_TX_DS  5
#define MASK_MAX_RT 4
#define EN_CRC      3
#define CRCO        2
#define PWR_UP      1
#define PRIM_RX     0

#define EN_AA 0x01
#define ENAA_P5 5
#define ENAA_P4 4
#define ENAA_P3 3
#define ENAA_P2 2
#define ENAA_P1 1
#define ENAA_P0 0

#define EN_RXADDR 0x02
#define ERX_P5 5
#define ERX_P4 4
#define ERX_P3 3
#define ERX_P2 2
#define ERX_P1 1
#define ERX_P0 0

#define SETUP_AW 0x03
#define AW_3_BYTES 0x01
#define AW_4_BYTES 0x02
#define AW_5_BYTES 0x03
#define set_addr_width(b, aw) b = (aw & 0x03)

// Setup retries

#define SETUP_RETR 0x04
#define ARD_250_US  0x00
#define ARD_500_US  0x01
#define ARD_750_US  0x02
#define ARD_1000_US 0x03
#define ARD_1250_US 0x04
#define ARD_1500_US 0x05
#define ARD_1750_US 0x06
#define ARD_2000_US 0x07
#define ARD_2250_US 0x08
#define ARD_2500_US 0x09
#define ARD_2750_US 0x0A
#define ARD_3000_US 0x0B
#define ARD_3250_US 0x0C
#define ARD_3500_US 0x0D
#define ARD_3750_US 0x0E
#define ARD_4000_US 0x0F
#define ARC_0  0x00
#define ARC_1  0x01
#define ARC_2  0x02
#define ARC_3  0x03
#define ARC_4  0x04
#define ARC_5  0x05
#define ARC_6  0x06
#define ARC_7  0x07
#define ARC_8  0x08
#define ARC_9  0x09
#define ARC_10 0x0A
#define ARC_11 0x0B
#define ARC_12 0x0C
#define ARC_13 0x0D
#define ARC_14 0x0E
#define ARC_15 0x0F
#define set_retrans_delay(b, rd) b = (b & 0x0F) | (rd << 4)
#define set_retrans_count(b, rc) b = (b & 0xF0) | (rc & 0xF0)

#define RF_CH 0x05
#define set_rf_channel(b, ch) b = (ch & 0x7F)

#define RF_SETUP 0x06
#define CONT_WAVE  7
#define RF_DR_LOW  5
#define PLL_LOCK   4
#define RF_DR_HIGH 3
#define RF_PWR_M_18_DB 0x00
#define RF_PWR_M_12_DB 0x01
#define RF_PWR_M_6_DB  0x02
#define RF_PWR_0_DB    0x02
#define set_rf_pwr(b, pwr) b = ((b & 0xF8) | (pwr & 0xF8)) >> 1

#define STATUS 0x07
#define RX_DR   6
#define TX_DS   5
#define MAX_RT  4
#define TX_FULL 0
#define get_rx_p_no(b) (b & 0x0E) >> 1

#define OBSERVE_TX 0x08
#define get_plos_cnt(b) (b & 0xF0) >> 4
#define get_arc_cnt(b) (b & 0x0F)

#define RPD 0x09

#define RX_ADDR_P0 0x0A
#define RX_ADDR_P1 0x0B
#define RX_ADDR_P2 0x0C
#define RX_ADDR_P3 0x0D
#define RX_ADDR_P4 0x0E
#define RX_ADDR_P5 0x0F

#define TX_ADDR 0x10

#define RX_PW_P0 0x11
#define RX_PW_P1 0x12
#define RX_PW_P2 0x13
#define RX_PW_P3 0x14
#define RX_PW_P4 0x15
#define RX_PW_P5 0x16

#define FIFO_STATUS 0x17
#define TX_REUSE 6
#define TX_FULL  5
#define TX_EMPTY 4
#define RX_FULL  1
#define RX_EMPTY 0

#define DYNPD 0x1C
#define DPL_5 5
#define DPL_4 4
#define DPL_3 3
#define DPL_2 2
#define DPL_1 1
#define DPL_0 0

#define FEATURE 0x1D
#define EN_DPL     2
#define EN_ACK_PAY 1
#define EN_DYN_ACK 0
