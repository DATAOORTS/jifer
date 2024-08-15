jifer() {
    # Add this inside .bashrc
    # if you are not installing jifer in home path where jifer binary is present you need to define manually your path at "$PWD/jifer"
    # Run the compiled C program located in the current directory to add the variable to .bashrc
    "$PWD/jifer" "$@"

    # Extract the variable name
    local var_name=$(echo "$1" | cut -d'=' -f1)

    # Export the variable in the current shell session
    eval "export $1"
}
