import requests
from datetime import date, timedelta

#parameter "yesterday" oznacuje prvy den, od ktoreho sa budu data stahovat
#parameter "days" je mozne zmenit na den od ktoreho sa budu data stahovat
#napriklad, ak chcete data pred 2 dnami,zadajte 2 
yesterday = date.today() - timedelta(days=10)
#parameter "today", je dnesny den
today = date.today()

url = "https://transparency.entsog.eu/api/v1/operationalData.xlsx?forceDownload=true&pointDirection=ua-tso-0001itp-00434exit,ua-tso-0001itp-00432exit,ua-tso-0001itp-00117exit,ua-tso-0001itp-00431exit,ua-tso-0001itp-00433exit&from="+str(yesterday)+"&to="+str(today)+"&indicator=Physical%20Flow&periodType=day&timezone=CET&limit=-1&dataset=1&directDownload=true"
response = requests.get(url=url)
with open("od_"+str(yesterday)+"_do_"+str(today)+ ".xlsx", "wb") as f:
    
    f.write(response.content)
