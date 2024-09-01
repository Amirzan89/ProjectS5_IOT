import network
import time
import socket
import ntptime
from machine import RTC

class NTP:
    _instance = None
    dateTime = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(NTP, cls).__new__(cls)
        return cls._instance

    def __init__(self):
        if not hasattr(self, 'initialized'):
            self.initialized = True
            ntptime.settime()
            self.dateTime = time.localtime(time.timezone + 7*3600)  # Add 7 hours to UTC time

    def get_time(self):
        return self.dateTime


# import time
# import ntptime
# from machine import RTC
# class NTP:
#     dateTime = None
#     def getTime(self):
#         ntptime.settime()
#         self.dateTime = time.localtime(time.timezone + 7 * 3600)
#         return self.dateTime