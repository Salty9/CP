g++-14 -DLOCAL_PROJECT -std=c++20 $1.cpp -o $1 && ./$1 < input

# Usage: bash build.sh filename_without_extension
# Or put this in keybindings.json for keyboard shortcut

# {
#     "key": "alt+enter",
#     "command": "workbench.action.terminal.sendSequence",
#     "args": {
#         "text": "bash build.sh ${fileBasenameNoExtension}\u000D"
#     //   \u000D is return (ie presses enter)
#     }
# }