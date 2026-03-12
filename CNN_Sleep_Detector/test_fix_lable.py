import json
import os

alt = {
    'right' : 'left',
    'left' : 'right',
    'rs':'ls',
    'ls':'rs'
}


for root, dirs, filenames in os.walk(r'eyes\image_eyes'):
    for filename in filenames:
        first, last = os.path.splitext(filename)
        if last != '.json':
            continue
        # root + '/' + filename
        path =  os.path.join(root, filename)
        data = json.load(open(path))
        for shape in data['shapes']:
            shape['label'] = alt[shape['label']]

        json.dump(data, open(path, 'w'))
        print(path)
