# Generates cp_snippets.json inside .vscode with snippets for VSCode
# change its file format to .code-snippets

import os
import json
import sys

snippets = {}

for subdir in os.walk('.'):
  if subdir[0] == '.' or '.git' in subdir[0]:
    continue
  for filename in subdir[2]:
    name, extension = filename.split('.')
    if extension != 'cpp':
      continue

    if name in snippets:
      print(f'error: duplicate snippet {name}', file=sys.stderr)
      exit(0)

    path = subdir[0] + '/' + filename
    with open(path, 'r') as f:
      snippet = {
        "prefix": name,
        "body": [line.rstrip() for line in f.readlines()],
        "description": name
      }
      snippets[name] = snippet

    print(f'generated snippet {name}', file=sys.stderr)

with open('.vscode/cp_snippets.json', 'w') as f:
  f.write(json.dumps(snippets, indent=2))

print('done', file=sys.stderr)