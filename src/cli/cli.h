#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define CLI_LINE_BUF_MAX 128
#define CLI_CMD_LIST_MAX 32
#define CLI_CMD_ARG_MAX 16
#define CLI_HIST_MAX 10
typedef void (*cli_callback_t)(void);


typedef enum {
    CLI_STATE_NORMAL = 0,
    CLI_STATE_ESC_SCVD,
    CLI_STATE_BRACKET_RCVD,
} cli_input_state_t;


void cliInit(void);
void cliMain(void);
void cliPrint(char *fmt, ...);
void cliADD(char *cmd_str,void (*cmd_func)(uint8_t argc,  char *argv[]));

void cliSetCtrlHandler(cli_callback_t handelr);
