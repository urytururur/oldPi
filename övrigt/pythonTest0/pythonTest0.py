# importing the requests library 
import requests 

#GET-REQUEST
# api-endpoint 
URL = "http://155.4.151.137/smarthome0/public/api/switch/1"
  
# sending get request and saving the response as response object 
r = requests.get(url = URL) 
  
# extracting data in json format 
data = r.json() 

#getting on-value
on = data['data']['on'];
print("on: ");
print(on);



#PUT-REQUEST
# defining the api-endpoint  
API_ENDPOINT = "http://155.4.151.137/smarthome0/public/api/switch/1"
  
# data to be sent to api 
data = {
    'on': 0
}

# sending post request and saving response as response object 
r = requests.put(url = API_ENDPOINT, data = data) 
  
# extracting response text  
pastebin_url = r.text 
print("The pastebin URL is:%s"%pastebin_url)