import requests
from aip import AipOcr

image = requests.get('https://static.pandateacher.com/7b5d6d8d9dea5691705d04fef2306b52.png').content

APP_ID = '11756541'
API_KEY = '2YhkLuyQGljPUYnmi1CFgxOP'
SECRET_KEY = '4rrHe2BF828bI8bQy6bLlx1MelXqa8Z7'

client = AipOcr(APP_ID, API_KEY, SECRET_KEY)
res = client.basicGeneral(image)

if 'words_result' in res.keys():
    for item in res['words_result']:
        print(item['words'])
else:
    print(res)
