/**Switch Case with Enums:
 * 
 * one of the best features of enums in C is that it can be used
 * in switch statements. What does this give me?
 *      🔹 Avoid 'magic numbers'
 *      🔹 Use descriptive names
 *      🔹 With modern tooling, will give me an error/warning if 
 *         I haven't handled all the cases in my match
 * 
 * Note that I have a break after each case. if I don't do that
 * then the next case will still execute: it "falls through" to
 * the next case. Many devs have written bugs when using switch
 * statements, cuz they forgot to add break.asm
 * 
 * There are some cases though in which I might want to fallthrough:
 * But according to Teej, its usually a footgun. I should almost 
 * always want a break at the end of each statement.asm
 * 
 * Assignment:asm
 */
#include <stdio.h>

typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
} log_level_t;

typedef enum {
    MINOR_1 = 1,
    MINOR_2,
    MINOR_3,
    MAJOR_4,
    MAJOR_5,
} error_t;

typedef enum {
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_NOT_FOUND = 404,
    HTTP_TEAPOT = 418,
    HTTP_INTERNAL_SERVER_ERROR = 500,
} HttpErrorCode;

char *http_to_str(HttpErrorCode code);

int main(int argc, char const *argv[])
{
    // note how Im using both LOG_NAMES and the numbers interchangeablly
    log_level_t loglevel = 1;

    switch (loglevel) {
        case 0:
            printf("Debug logging enabled\n");
            break;
        case 1:
            printf("Info logging enabled\n");
            break;
        case 2:
            printf("Warning logging enabled\n");
            break;
        case LOG_ERROR:
            printf("Error logging enabled\n");
            break;
        default:
            printf("Unknown log level: %d\n",loglevel);
            break;
    }


    // Here we just use the numbers
    error_t error_code = MAJOR_4;

    switch (error_code) {
        case 1:
        case 2:
        case 3:
            // 1,2, and 3 are all minor errors
            printf("Minor error occured. Please try again.\n");
            break;
        case 4:
        case 5:
            // 4 and 5 are major errors
            printf("Major error occurred. Restart required.\n");
            break;
        default:
            printf("Unknown error.\n");
            break;
    }

    HttpErrorCode code = HTTP_NOT_FOUND;
    printf("Error Code Message: %s\n",http_to_str(code));

    return 0;
}

char *http_to_str(HttpErrorCode code) {
    switch (code) {
        case HTTP_BAD_REQUEST:
            return "400 Bad Request";
            break;
        case HTTP_UNAUTHORIZED:
            return "401 Unauthorized";
            break;
        case HTTP_NOT_FOUND:
            return "404 Not Found";
            break;
        case  HTTP_TEAPOT:
            return "418 I AM A TEAPOT!";
            break;
        case HTTP_INTERNAL_SERVER_ERROR:
            return "500 Internal Server Error";
            break;
        default:
            return "Unknown HTTP status code";
            break;
    }
}
