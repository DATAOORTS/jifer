jifer() {
    # Run the compiled C program located in the current directory to add the variable to .bashrc
    "$PWD/jifer" "$@"

    # Extract the variable name
    local var_name=$(echo "$1" | cut -d'=' -f1)

    # Export the variable in the current shell session
    eval "export $1"
}
