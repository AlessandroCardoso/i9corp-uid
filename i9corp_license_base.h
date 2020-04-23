/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   license.h
 * Author: Sileno Brito
 *
 * Created on 17 de Fevereiro de 2018, 09:16
 */

#ifndef LICENSE_H
#define LICENSE_H

#include <i9corp/structures/i9corp_entry_set.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct i9corp_license_base_property_t {
        long length;
        long position;
        char * name;
        long value;
    } i9corp_license_base_property;

    typedef struct i9corp_license_base_divisor_t {
        long position;
    } i9corp_license_base_divisor;

    typedef struct i9corp_license_base_t {
        char * dicionary;
        char * hash;
        char * serial;

        struct entry * properties;
        struct entry* divisors;
        long length;
    } i9corp_license_base;

    i9corp_license_base * license_new();
    i9corp_license_base * license_init(const char *xml_file_settings);
    void license_property_set(i9corp_license_base * license, const char *name, long length);
    void license_dictionary_set(i9corp_license_base * license, const char *dictionary);
    void license_divisor_set(i9corp_license_base * license, long position);
    int license_set_property_value(i9corp_license_base * license, const char *name, long value);
    long license_get_property_value(i9corp_license_base * license, const char *name);
    int license_check_serial(const char *xml_file_settings, const char *serial, const long salt);
    int license_check_hash(i9corp_license_base * license, long salt);

    void license_import_serial(i9corp_license_base * license, const char *serial, const long salt);
    void license_free(i9corp_license_base *license);

    void license_refresh_serial(i9corp_license_base * license, long salt);
    void license_hash_set(i9corp_license_base * license, const char *hash);
#ifdef __cplusplus
}
#endif

#endif /* LICENSE_H */

