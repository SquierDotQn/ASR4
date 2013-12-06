#include <stdlib.h>
#include <string.h>

#include "minunit.h"
#include "chaine.h"


/****************** mon_strlen *******************/

MU_SETUP(mon_strlen) {
}
MU_TEAR_DOWN(mon_strlen) {
}
MU_TEST(mon_strlen, strlen5) {
    MU_ASSERT_EQUAL(mon_strlen("12345"), 5) ;
}
MU_TEST(mon_strlen, strlen0) {
    MU_ASSERT_EQUAL(mon_strlen(""), 0) ;
}
MU_TEST(mon_strlen, strlen_multi0) {
    char str[] = {'A','A','A','A','A','A','\0','A','A','\0'} ;
    MU_ASSERT_EQUAL(mon_strlen(str), 6) ;
}
MU_TEST(mon_strlen, strlen_non_ascii) {
    MU_ASSERT_EQUAL(mon_strlen("12345ééé"), 8) ;
}
MU_TEST_SUITE(mon_strlen) = {
    MU_ADD_TEST(mon_strlen, strlen5),
    MU_ADD_TEST(mon_strlen, strlen0),
    MU_ADD_TEST(mon_strlen, strlen_multi0),
/*    MU_ADD_TEST(mon_strlen, strlen_non_ascii),Non pertinent */
    MU_TEST_SUITE_END
} ;
/****************** mon_strcmp *******************/
MU_SETUP(mon_strcmp) {
}
MU_TEAR_DOWN(mon_strcmp) {
}
MU_TEST(mon_strcmp, mon_strcmp_a_equals_b_vide) {
    MU_ASSERT_EQUAL(mon_strcmp("",""), 0) ;
}
MU_TEST(mon_strcmp, mon_strcmp_a_equals_b_non_vide) {
    MU_ASSERT_EQUAL(mon_strcmp("UIO","UIO"), 0) ;
}
MU_TEST(mon_strcmp, mon_strcmp_a_less_than_b) {
    MU_ASSERT_LESS(mon_strcmp("BCD","EF"), 0) ;
}
MU_TEST(mon_strcmp, mon_strcmp_a_left_factor_of_b) {
    MU_ASSERT_LESS(mon_strcmp("BCD","BCDYU"), 0) ;
}
MU_TEST(mon_strcmp, mon_strcmp_a_greater_than_b) {
    MU_ASSERT_GREATER(mon_strcmp("KCD","EF"), 0) ;
}
MU_TEST(mon_strcmp, mon_strcmp_a_greater_than_b_vide) {
    MU_ASSERT_GREATER(mon_strcmp("AZE",""), 0) ;
}
MU_TEST_SUITE(mon_strcmp) = {
    MU_ADD_TEST(mon_strcmp, mon_strcmp_a_equals_b_vide),
    MU_ADD_TEST(mon_strcmp, mon_strcmp_a_equals_b_non_vide),
    MU_ADD_TEST(mon_strcmp, mon_strcmp_a_less_than_b),
    MU_ADD_TEST(mon_strcmp, mon_strcmp_a_left_factor_of_b),
    MU_ADD_TEST(mon_strcmp, mon_strcmp_a_greater_than_b),
    MU_ADD_TEST(mon_strcmp, mon_strcmp_a_greater_than_b_vide),
    MU_TEST_SUITE_END
} ;
/****************** mon_strncmp *******************/
MU_SETUP(mon_strncmp) {
}
MU_TEAR_DOWN(mon_strncmp) {
}
MU_TEST(mon_strncmp, mon_strncmp_a_equals_b_vide) {
    MU_ASSERT_EQUAL(mon_strncmp("","", 0), 0) ;
}
MU_TEST(mon_strncmp, mon_strncmp_a_equals_b_n_too_large) {
    MU_ASSERT_EQUAL(mon_strncmp("","", 6), 0) ;
}
MU_TEST(mon_strncmp, monstrncmp_n_restrict) {
    MU_ASSERT_EQUAL(mon_strncmp("ABCDEF","ABCTYU", 3), 0) ;
}
MU_TEST(mon_strncmp, monstrncmp_a_greater) {
    MU_ASSERT_GREATER(mon_strncmp("ABDTYY","ABCTYU", 3), 0) ;
}
MU_TEST(mon_strncmp, monstrncmp_a_lower) {
    MU_ASSERT_LESS(mon_strncmp("ABBWYY","ABCTYU", 3), 0) ;
}
MU_TEST_SUITE(mon_strncmp) = {
    MU_ADD_TEST(mon_strncmp, mon_strncmp_a_equals_b_vide),
    MU_ADD_TEST(mon_strncmp, mon_strncmp_a_equals_b_n_too_large),
    MU_ADD_TEST(mon_strncmp, monstrncmp_n_restrict),
    MU_ADD_TEST(mon_strncmp, monstrncmp_a_greater),
    MU_ADD_TEST(mon_strncmp, monstrncmp_a_lower),
    MU_TEST_SUITE_END
} ;
/****************** mon_strcat *******************/
#define SIZE (128)
#define MAGIC (-1)
char dest[SIZE] ;

MU_SETUP(mon_strcat) {
    int i ;
    for (i = 0 ; i < SIZE ; i++) {
        dest[i] = MAGIC ;
    }
}
MU_TEAR_DOWN(mon_strcat) {
}
MU_TEST(mon_strcat, mon_strcat_a_et_b_non_vides) {
    char *result ;
    strcpy(dest, "PREM") ;
    result = mon_strcat(dest, "IJKLM") ;
    MU_ASSERT_EQUAL(strcmp(result,"PREMIJKLM"), 0) ;
}
MU_TEST(mon_strcat, mon_strcat_a_et_b_vide) {
    char *result ;
    strcpy(dest, "") ;
    result = mon_strcat(dest, "") ;
    MU_ASSERT_EQUAL(strcmp(result,""), 0) ;
}
MU_TEST(mon_strcat, mon_strcat_a_vide_et_b) {
    char *result ;
    strcpy(dest, "") ;
    result = mon_strcat(dest, "IJKLM") ;
    MU_ASSERT_EQUAL(strcmp(result,"IJKLM"), 0) ;
}
MU_TEST(mon_strcat, mon_strcat_a_b_vide) {
    char *result ;
    strcpy(dest, "PREM") ;
    result = mon_strcat(dest, "") ;
    MU_ASSERT_EQUAL(strcmp(result,"PREM"), 0) ;
}
MU_TEST_SUITE(mon_strcat) = {
    MU_ADD_TEST(mon_strcat, mon_strcat_a_et_b_non_vides),
    MU_ADD_TEST(mon_strcat, mon_strcat_a_et_b_vide),
    MU_ADD_TEST(mon_strcat, mon_strcat_a_vide_et_b),
    MU_ADD_TEST(mon_strcat, mon_strcat_a_b_vide),
    MU_TEST_SUITE_END
} ;

/****************** mon_strchr *******************/
#define SIZE (128)
#define MAGIC (-1)
char dest[SIZE] ;

MU_SETUP(mon_strchr) {
}
MU_TEAR_DOWN(mon_strchr) {
}
MU_TEST(mon_strchr, mon_strchr_c_found) {
    const char *str = "ABCDEF" ;
    const char *result ;
    result = mon_strchr(str, 'D') ;
    MU_ASSERT_EQUAL(result, str+3) ;
}
MU_TEST(mon_strchr, mon_strchr_c_not_found) {
    const char *str = "ABCDEF" ;
    const char *result ;
    result = mon_strchr(str, 'G') ;
    MU_ASSERT_EQUAL(result, NULL) ;
}
MU_TEST(mon_strchr, mon_strchr_c_first_found) {
    const char *str = "ABCDECFG" ;
    const char *result ;
    result = mon_strchr(str, 'C') ;
    MU_ASSERT_EQUAL(result, str+2) ;
}
MU_TEST(mon_strchr, mon_strchr_empty_string) {
    const char *str = "" ;
    const char *result ;
    result = mon_strchr(str, 'C') ;
    MU_ASSERT_EQUAL(result, NULL) ;
}
MU_TEST_SUITE(mon_strchr) = {
    MU_ADD_TEST(mon_strchr, mon_strchr_c_found),
    MU_ADD_TEST(mon_strchr, mon_strchr_c_not_found),
    MU_ADD_TEST(mon_strchr, mon_strchr_c_first_found),
    MU_ADD_TEST(mon_strchr, mon_strchr_empty_string),
    MU_TEST_SUITE_END
} ;

/****************** mon_strstr *******************/

MU_SETUP(mon_strstr) {
}
MU_TEAR_DOWN(mon_strstr) {
}
MU_TEST(mon_strstr, mon_strstr_str_found) {
    const char *str = "0123456789" ;
    const char *result ;
    result = mon_strstr(str, "345") ;
    MU_ASSERT_EQUAL(result, str+3) ;
}
MU_TEST(mon_strstr, mon_strstr_str_not_found) {
    const char *str = "0123456789" ;
    const char *result ;
    result = mon_strstr(str, "346") ;
    MU_ASSERT_EQUAL(result, NULL) ;
}
MU_TEST(mon_strstr, mon_strstr_str_vide) {
    const char *str = "" ;
    const char *result ;
    result = mon_strstr(str, "CDEZ") ;
    MU_ASSERT_EQUAL(result, NULL) ;
}
MU_TEST(mon_strstr, mon_strstr_needle_vide) {
    const char *str = "0123456789" ;
    const char *result ;
    result = mon_strstr(str, "") ;
    MU_ASSERT_EQUAL(result, str) ;
}
MU_TEST(mon_strstr, mon_strstr_not_found_ends) {
    const char *str = "0123456789" ;
    const char *result ;
    result = mon_strstr(str, "789A") ;
    MU_ASSERT_EQUAL(result, NULL) ;
}
MU_TEST(mon_strstr, mon_strstr_found_ends) {
    const char *str = "0123456789" ;
    const char *result ;
    result = mon_strstr(str, "789") ;
    MU_ASSERT_EQUAL(result, str+7) ;
}

MU_TEST_SUITE(mon_strstr) = {
    MU_ADD_TEST(mon_strstr, mon_strstr_str_found),
    MU_ADD_TEST(mon_strstr, mon_strstr_str_not_found),
    MU_ADD_TEST(mon_strstr, mon_strstr_str_vide),
    MU_ADD_TEST(mon_strstr, mon_strstr_needle_vide),
    MU_ADD_TEST(mon_strstr, mon_strstr_not_found_ends),
    MU_ADD_TEST(mon_strstr, mon_strstr_found_ends),
    MU_TEST_SUITE_END
} ;

/****************** main *******************/
int main(int argc, char **argv) {
    MU_RUN_TEST_SUITE_WITH_REPORT(mon_strlen) ;
    MU_RUN_TEST_SUITE_WITH_REPORT(mon_strcmp) ;
    MU_RUN_TEST_SUITE_WITH_REPORT(mon_strncmp) ;
    MU_RUN_TEST_SUITE_WITH_REPORT(mon_strcat) ;
    MU_RUN_TEST_SUITE_WITH_REPORT(mon_strchr) ;
    MU_RUN_TEST_SUITE_WITH_REPORT(mon_strstr) ;
    return 0 ;
}
