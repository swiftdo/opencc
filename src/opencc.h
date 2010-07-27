/*
* Open Chinese Convert
*
* Copyright 2010 BYVoid <byvoid.kcp@gmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef __OPENCC_H_
#define __OPENCC_H_

#include "opencc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Headers from C standard library
 */
#include <stddef.h>

/* Macros */
#define OPENCC_DEFAULT_CONFIG_SIMP_TO_TRAD "zhs2zht.ini"
#define OPENCC_DEFAULT_CONFIG_TRAD_TO_SIMP "zht2zhs.ini"

/**
 * opencc_open:
 * @config_file: Location of configuration file.
 * @returns: A description pointer of the newly allocated instance of opencc.
 *
 * Make an instance of opencc.
 *
 * Note: Leave config_file to NULL if you do not want to load any configuration file.
 * 
 */
opencc_t opencc_open(const char * config_file);

/**
 * opencc_close:
 * @od: The description pointer.
 * @returns: 0 on success or non-zero number on failure.
 *
 * Destroy an instance of opencc.
 *
 */
int opencc_close(opencc_t od);

/**
 * opencc_convert:
 * @od: The description pointer.
 * @inbuf: The pointer to the wide character string of the input buffer.
 * @inbufleft: The maximum number of characters in *inbuf to convert.
 * @outbuf: The pointer to the wide character string of the output buffer.
 * @outbufleft: The size of output buffer.
 *
 * @returns: The number of characters of the input buffer that converted.
 *
 * Convert string from *inbuf to *outbuf.
 *
 * Note: Don't forget to assign **outbuf to L'\0' after called.
 *
 */
size_t opencc_convert(opencc_t od, ucs4_t ** inbuf, size_t * inbufleft,
		ucs4_t ** outbuf, size_t * outbufleft);

char * opencc_convert_utf8(opencc_t odt, const char * inbuf, size_t length);

int opencc_dict_load(opencc_t odt, const char * dict_filename,
		opencc_dictionary_type dict_type);

/**
 * opencc_errno:
 *
 * @returns: The error number.
 *
 * Return an opencc_convert_errno_t which describes the last error that occured or
 * OPENCC_CONVERT_ERROR_VOID
 *
 */
opencc_error opencc_errno(void);

/**
 * opencc_perror:
 * @spec Prefix message.
 *
 * Print the error message to stderr.
 *
 */
void opencc_perror(const char * spec);

#ifdef __cplusplus
};
#endif

#endif /* __OPENCC_H_ */
