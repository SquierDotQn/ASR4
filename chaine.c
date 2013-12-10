#include <stdio.h>
#include "chaine.h"


#ifdef STRLEN_PTR
int mon_strlen(const char *s){
	int i=0;
	while(*(s+i)!='\0'){
		i++;
	}
	return i;
}

#else
int mon_strlen(const char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
#endif

int mon_strcmp(const char *s1, const char *s2){
	int i=0;
	while(*(s1+i)!='\0'||*(s2+i)!='\0'){
		if(*(s1+i)==*(s2+i)){
			i++;
		} else if(*(s1+i)>*(s2+i)){
			return 1;
		} else if(*(s1+i)<*(s2+i)){
			return -1;
		}
	}
	if(mon_strlen(s1)>mon_strlen(s2)){
		return 1;
	} else if( mon_strlen(s2)>mon_strlen(s1)){
		return -1;
	}
	return 0;
}

int mon_strncmp(const char *s1, const char *s2, int n){
	int i=0;
	while((*(s1+i)!='\0'||*(s1+i)!='\0') && i<n){
		if(*(s1+i)==*(s2+i)){
			i++;
		} else if(*(s1+i)>*(s2+i)){
			return 1;
		} else if(*(s1+i)<*(s2+i)){
			return -1;
		}
	}
	if((mon_strlen(s1)<n)||(mon_strlen(s2)<n)){
		if(mon_strlen(s1)>mon_strlen(s2)){
			return 1;
		} else if( mon_strlen(s2)>mon_strlen(s1)){
			return -1;
		}
	}
	return 0;
}

char *mon_strcat(char *s1, const char *s2){
	int lens1 = mon_strlen(s1);
	int lens2 = mon_strlen(s2);
	int i;
	for(i=0;i<=lens2;i++)
		*(s1+i+lens1)=*(s2+i);
	return s1 ;
}

char *mon_strchr(const char *s, int c){
	int i=0;
	while(*(s+i)!='\0'){
		if(*(s+i)==c)
			return (char*)(s+i);
		i++;
	}
	return NULL;
}

char *mon_strstr(const char *haystack, const char *needle){
	int h_size = mon_strlen(haystack), n_size = mon_strlen(needle);
	int i=0, j=0, k=0;
	if(n_size==0){
		return NULL;
	}/*
	while(i+n_size < h_size){
		if(*(haystack+i) == *(needle)){
			k = 0;
			j = 0;
			for(k = i; k<n_size+i;k++){
				if(*(haystack+k) != *(needle+j) && *(needle+j) != '\0'&& *(i+haystack) != '\0'){
					break;
				}
				j++;
			}
			if(*(needle+j) == '\0'){
				return (char*)(haystack+i);
			}
		}	
		i++;
	}*/
	while(i<h_size-n_size){
		haystack=haystack+i;
		if(mon_strncmp(haystack, needle, n_size)==0)
			return (char*)haystack+i;
	}
	return NULL;
}
