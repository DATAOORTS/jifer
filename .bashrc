jifer() {
    # You have to add this in .bashrc
    # Find the location of the jifer binary
    local jifer_path
    jifer_path=$(command -v jifer)

    if [ -z "$jifer_path" ]; then
        echo "Error: jifer command not found. Please ensure it is in your PATH."
        return 1
    fi

    # Run the compiled C program to add the variable to .bashrc
    "$jifer_path" "$@"

    # Extract the variable name
    local var_name=$(echo "$1" | cut -d'=' -f1)

    # Export the variable in the current shell session
    eval "export $1"
}
