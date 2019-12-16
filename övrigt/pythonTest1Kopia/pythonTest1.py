import requests 
import time

data = 0;
while True:
    #GET
    URL = "http://192.168.0.101/api/v6LjMGOqrWBY440pvcpkFyd3K7uY6SQMeRWZJ6SA/lights/"
    r = requests.get(url = URL) 

    if data == r.json():
        None
    else:
        data = r.json()

        index = 1
        for i in data:
            #PUT
            API_ENDPOINT = "http://155.4.151.137/smarthome0/public/api/huelight/" + str(index);

            try:
                test = data.get(i)['state']['hue']
            except:
                test = None

            if data.get(i)['state']['on'] == True:
                on = 1
            else:
                on = 0

            if test == None:
                putData = {
                    "on": on,   
                    "bri": data.get(i)['state']['bri'],
                    "hue": -1,
                    "sat": -1
                }
            else:
                putData = {
                    "on": on,
                    "bri": data.get(i)['state']['bri'],
                    "hue": data.get(i)['state']['hue'],
                    "sat": data.get(i)['state']['sat']
                }
            #send
            r = requests.put(url = API_ENDPOINT, data = putData)

            #get payload
            pastebin_url = r.text 
            print("PAYLOAD: %s"%pastebin_url + "\n")

            index += 1;
            time.sleep(0.1);

time.sleep(0.1)