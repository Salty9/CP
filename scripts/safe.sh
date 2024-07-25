g++-14 -DLOCAL -Wall -Wextra -pedantic -std=c++20 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector $1.cpp -o $1 && ./$1 < input

# Usage: bash safe.sh filename_without_extension
# Or put this in keybindings.json for keyboard shortcut

# {
#     "key": "alt+shift+enter",
#     "command": "workbench.action.terminal.sendSequence",
#     "args": {
#         "text": "bash safe.sh ${fileBasenameNoExtension}\u000D"
#     //   \u000D is return (ie presses enter)
#     }
# }