#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_FILE ".bashrc"

void add_env_var_to_file(const char *var, const char *value) {
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        fprintf(stderr, "Error: Could not find home directory.\n");
        exit(EXIT_FAILURE);
    }

    // Path to .bashrc file
    char config_path[1024];
    snprintf(config_path, sizeof(config_path), "%s/%s", home_dir, CONFIG_FILE);

    // Open .bashrc in append mode
    FILE *file = fopen(config_path, "a");
    if (file == NULL) {
        perror("Error opening config file");
        exit(EXIT_FAILURE);
    }

    // Write the export command
    fprintf(file, "export %s=\"%s\"\n", var, value);
    fclose(file);
    
    // Notify the user that the variable has been added
    printf("Successfully added %s=\"%s\" to %s\n", var, value, config_path);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s VAR=\"VALUE\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse input argument to extract the variable name and value
    char *input = argv[1];
    char *equals_sign = strchr(input, '=');
    if (equals_sign == NULL) {
        fprintf(stderr, "Error: Invalid format. Use VAR=\"VALUE\".\n");
        return EXIT_FAILURE;
    }

    *equals_sign = '\0';
    char *var = input;
    char *value = equals_sign + 1;

    // Remove surrounding quotes if present
    if (value[0] == '\"') {
        value++;
        value[strlen(value) - 1] = '\0';
    }

    // Add the variable to .bashrc
    add_env_var_to_file(var, value);

    return EXIT_SUCCESS;
}
