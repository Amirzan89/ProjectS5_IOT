import utime
import time
from .server.NTP import NTP
from const import Const
def timer():
    ntp = NTP()
    ntp.get_time()
    # current_time = utime.time()
    # desired_time = current_time + Const.timerTimeout
    # while utime.time() < desired_time:
    #     time.sleep_ms(1000)
    # return
    desired_time = utime.time() + Const.timerTimeout
    while utime.time() < desired_time:
        time.sleep_ms(1000)
    return