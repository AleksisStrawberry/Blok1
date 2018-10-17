#include "Dictionary.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>


Dictionary * dict_new(){
	Dictionary *dictionary = (Dictionary *)malloc(sizeof(Dictionary));

	assert(dictionary != NULL);

	dictionary->head = NULL;
	dictionary->tail = NULL;
	return dictionary;


}

void dict_add(Dictionary * dictionary, const char *key, int value)
{
	//za sada ne bih brisanje ubacivala 
	//if (dict_has(dictionary, key))
		//dict_remove(dictionary, key);


	if (dictionary->head != NULL) {
		while (dictionary->tail != NULL) {
			dictionary = dictionary->tail;
		}
		Dictionary *next = dict_new();
		dictionary->tail = next;
		dictionary = dictionary->tail;
	}


	int key_length = strlen(key) + 1;
	dictionary->head = (KVPair*)malloc(sizeof(KVPair));
	assert(dictionary->head != NULL);
	dictionary->head->key = (char *)malloc(key_length * sizeof(char));
	assert(dictionary->head->key != NULL);
	strcpy(dictionary->head->key, key);
	dictionary->head->value = value;
}




int dict_has(Dictionary * dictionary, const char *key)
{

	if (dictionary->head == NULL)
		return 0;
	while (dictionary != NULL)
	{
		if (strcmp(dictionary->head->key, key) == 0)
			return 1;
		dictionary = dictionary->tail;
	}

	return 0;
}


int dict_get(Dictionary *dictionary, const char *key) {
	if (dictionary->head == NULL)
		return 0;
	while (dictionary != NULL) {
		if (strcmp(dictionary->head->key, key) == 0)
			return dictionary->head->value; //samo vratim tu vrednost 
		dictionary = dictionary->tail;
	}
	return 0;
}


void dict_free(Dictionary *dictionary) {
	if (dictionary == NULL)
		return;
	free(dictionary->head->key);
	free(dictionary->head);
	Dictionary *tail = dictionary->tail;
	free(dictionary);
	dict_free(tail);
}



