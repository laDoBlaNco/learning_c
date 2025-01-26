
// void concat_strings(char* str1, const char* str2){
//     int null_index = 0;
//     for (int i = 0; i < sizeof(str1); i++) {
//         // interestingly the fix was matching 0 and not '\0'
//         if (str1[i] == 0) {
//             null_index = i;
//             break;
//         }
//     }

//     for (int i = 0; i < sizeof(str2); i++) {
//         str1[null_index] = str2[i];
//         null_index++;
//     }
//     str1[null_index] = '\0';
//     printf("%s\n",str1);

// }