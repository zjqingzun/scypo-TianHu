#include "syssware.h"
#include "test.h"




// main()
int main() {
    //__CCU__();

    const char *file_path = "resrc/erno/ERNO.json";
    const char *test_error_codes[] = {"404", "500", "401", "999"};
    int num_tests = sizeof(test_error_codes) / sizeof(test_error_codes[0]);

    // Create a sample JSON file if it doesn't exist
    FILE *file = fopen(file_path, "w");
    if (file) {
        fprintf(file, "{\n"
                      "    \"400\": {\n"
                      "        \"message\": \"Bad Request\",\n"
                      "        \"description\": \"The request data is invalid or missing required information\",\n"
                      "        \"suggestion\": \"Check the input data and try again\"\n"
                      "    },\n"
                      "    \"401\": {\n"
                      "        \"message\": \"Unauthorized\",\n"
                      "        \"description\": \"You need to provide valid authentication credentials to access this resource\",\n"
                      "        \"suggestion\": \"Log in again or verify your credentials\"\n"
                      "    },\n"
                      "    \"403\": {\n"
                      "        \"message\": \"Forbidden\",\n"
                      "        \"description\": \"You do not have permission to access this resource\",\n"
                      "        \"suggestion\": \"Contact the administrator to gain access\"\n"
                      "    },\n"
                      "    \"404\": {\n"
                      "        \"message\": \"Not Found\",\n"
                      "        \"description\": \"The requested resource does not exist on the server\",\n"
                      "        \"suggestion\": \"Check the URL or contact the administrator\"\n"
                      "    },\n"
                      "    \"500\": {\n"
                      "        \"message\": \"Internal Server Error\",\n"
                      "        \"description\": \"An error occurred on the server, unable to process the request\",\n"
                      "        \"suggestion\": \"Try again later or contact the support team\"\n"
                      "    }\n"
                      "}");
        fclose(file);
    } else {
        fprintf(stderr, "Cannot create sample JSON file\n");
        return 1;
    }

    // Load error messages from JSON file
    cJSON *error_data = load_error_messages(file_path);
    if (!error_data) {
        return 1;
    }

    // Test with various error codes
    for (int i = 0; i < num_tests; i++) {
        get_error_message(test_error_codes[i], error_data);
    }

    // Free memory
    cJSON_Delete(error_data);

    return 0;
}