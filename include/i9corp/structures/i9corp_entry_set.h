/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   entry_set.h
 * Author: Sileno Brito
 *
 * Created on 18 de Fevereiro de 2018, 07:52
 */

#ifndef ENTRY_SET_H
#define ENTRY_SET_H

#ifdef __cplusplus
extern "C" {
#endif

    struct entry_node {
        char *key;
        void * data;
        struct entry_node *next;
        struct entry_node *back;
    };

    struct entry {
        void (*free)(void *);
        struct entry_node *root;
        long length;
    };

    struct entry * entry_new(void (*fn_free)(void *));
    void entry_set(struct entry * entry, const char *key, void *data);
    void entry_del(struct entry * entry, const char *key);
    void entry_free(struct entry * entry);

#ifdef __cplusplus
}
#endif

#endif /* ENTRY_SET_H */

