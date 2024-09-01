from camera import CosCamera
import server.WifiManager as WifiManager
def main():
    wlan = WifiManager.get_connection()
    if wlan is None:
        print("Could not initialize the network connection.")
        while True:
            pass

    CosCamera()
    while True:
        # pict = get_picture()
        # dataReq = procesPict()
        send_data_server(dataReq)
        timer()
if __name__ == "__main__":
    main()