#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#include <stdint.h>

typedef enum {
    NORMAL = 0
} message_type_t;

/**
 * @brief Message structure.
 *
 * A message structure is 12 bytes in length and is composed of three
 * parts: the payload (9 bytes), the message type (1 byte), and a CRC (2
 * bytes).
 *
 * @note Lors de la préparation d'un message pour transmission, vous
 * devez au minimum spécifier le type (utiliser une valeur comprise
 * entre 0 et 127 pour les messages utilisateur) et le CRC (utiliser
 * la fonction message_crc() à cet effet).
 *
 * @see message_crc, kilo_message_rx, kilo_message_tx,
 * kilo_message_tx_success
 */
typedef struct {
    uint8_t data[9]; ///< message payload.
    uint8_t type;    ///< message type. 
    uint16_t crc;    ///< message crc.
} message_t;

typedef struct Position Position;
struct Position{
	uint8_t x;
	uint8_t y;
	uint8_t time;
	int own_gradient;
};

typedef struct Target Target;
struct Target{
	uint8_t x;
	uint8_t y;
	uint8_t time;
};

typedef struct Next_wp Next_wp;
struct Next_wp{
    uint8_t x;
    uint8_t y;
    uint8_t time;
};

typedef struct Inter Inter;
struct Inter{
	Position position;
	Target target;
	Next_wp next_wp;
	int own_gradient;
};


typedef struct {
    Position position[9]; ///< message payload.
    uint8_t type;    ///< message type. 
    uint16_t crc;    ///< message crc.
} message_t_perso;

#endif//__MESSAGES_H__
