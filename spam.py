import os
from pystyle import Colors, Colorate
import requests
import time

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def main():
    R = Colors.red
    G = Colors.green
    W = Colors.white

    clear()
    banner = """
   __      __               ___________                        
  /  \    /  \ __ __  ______\__    ___/____  _____     _____   
  \   \/\/   /|  |  \/  ___/  |    | _/ __ \ \__  \   /     \  
   \        / |  |  /\___ \   |    | \  ___/  / __ \_|  Y Y  \ 
    \__/\  /  |____//____  >  |____|  \___  >(____  /|__|_|  / 
         \/              \/               \/      \/       \/  
                                     by WusThanhTu          
    """
    print(Colorate.Vertical(Colors.blue_to_purple, banner))
    
    nglusername = input("Username: ")
    message = input("Message: ")
    Count = int(input("Count: "))

    headers = {
        'accept': '*/*',
        'accept-language': 'vi-VN,vi;q=0.9,fr-FR;q=0.8,fr;q=0.7,en-US;q=0.6,en;q=0.5,mni-Mtei;q=0.4,mni;q=0.3',
        'content-type': 'application/x-www-form-urlencoded; charset=UTF-8',
        'origin': 'https://ngl.link',
        'priority': 'u=1, i',
        'referer': 'https://ngl.link/nguyendai11783?fbclid=PAZXh0bgNhZW0CMTEAAaau0hLPi8kjiUBzYj4ILgTHxs5bDYFhXNhttAKLs5_ekqQFe-3yOJdm9g0_aem_y1rDtNrx6IETP5J9jIZFmQ',
        'sec-ch-ua': '"Not(A:Brand";v="99", "Google Chrome";v="133", "Chromium";v="133"',
        'sec-ch-ua-mobile': '?0',
        'sec-ch-ua-platform': '"Windows"',
        'sec-fetch-dest': 'empty',
        'sec-fetch-mode': 'cors',
        'sec-fetch-site': 'same-origin',
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/133.0.0.0 Safari/537.36',
        'x-requested-with': 'XMLHttpRequest',
        # 'cookie': '_ga=GA1.1.1972795312.1742181165; mp_e8e1a30fe6d7dacfa1353b45d6093a00_mixpanel=%7B%22distinct_id%22%3A%20%22%24device%3A195a216df885b8-066f4f6ee80f4b-26011a51-144000-195a216df895b9%22%2C%22%24device_id%22%3A%20%22195a216df885b8-066f4f6ee80f4b-26011a51-144000-195a216df895b9%22%2C%22%24initial_referrer%22%3A%20%22%24direct%22%2C%22%24initial_referring_domain%22%3A%20%22%24direct%22%2C%22__mps%22%3A%20%7B%7D%2C%22__mpso%22%3A%20%7B%22%24initial_referrer%22%3A%20%22%24direct%22%2C%22%24initial_referring_domain%22%3A%20%22%24direct%22%7D%2C%22__mpus%22%3A%20%7B%7D%2C%22__mpa%22%3A%20%7B%7D%2C%22__mpu%22%3A%20%7B%7D%2C%22__mpr%22%3A%20%5B%5D%2C%22__mpap%22%3A%20%5B%5D%7D; _ga_5DV1ZR5ZHG=GS1.1.1742181164.1.1.1742181283.0.0.0',
    }

    
    data = {
        "username": nglusername,
        "question": message,
        "deviceId": "",
        "gameSlug": "",
        "referrer": ""
    }

    value = 0
    notsend = 0

    while value < Count:
        response = requests.post("https://ngl.link/api/submit", headers=headers, data=data)
        if response.status_code == 200:
            value += 1
            print(f"{G}[+] Power By WusThanhTu => {nglusername} {value}")
        else:
            notsend += 1
            print(f"{R}[-] Error")
        
        time.sleep(1)

if __name__ == "__main__":
    main()