import time
i=0
while (i<=10):
    i=i+1
    time.sleep(1)
    
    import random
    temperature=random.randint(0,30)
    humidity=random.randint(1,100)
    if temperature<=15:
        print(temperature, "temperature is low")
    elif temperature<=25:
        print(temperature, "temperature is normal")
    else :
        print(temperature, "temperature is high")
    if humidity<=30:
        print(humidity, "humidity is low ")
    elif humidity<=60:
        print(humidity, "humidity is normal")
    else :
        print(humidity, "humidity is high")

