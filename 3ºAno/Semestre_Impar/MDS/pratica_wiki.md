# Getting started with the Elastic Stack
Looking for an Elastic Stack ("ELK" tutorial) that shows how to set up the Elastic Shack? In this tutorial, you learn how to get up and running quickly. First you install the core open source products:

- [Elasticsearch](https://www.elastic.co/guide/en/elastic-stack-get-started/current/get-started-elastic-stack.html#install-elasticsearch)
- [Kibana](https://www.elastic.co/guide/en/elastic-stack-get-started/current/get-started-elastic-stack.html#install-kibana)
- [Beats](https://www.elastic.co/guide/en/elastic-stack-get-started/current/get-started-elastic-stack.html#install-beats)
- [Logstash](https://www.elastic.co/guide/en/elastic-stack-get-started/current/get-started-elastic-stack.html#install-logstash)

Then you learn how to implement a system monitoring solution that uses Metricbeat to collect server metrics and ship the data to Elasticsearch, where you can search and visualize the data by using Kibana. After you get the basic setup working, you add Logstash for additional parsing.

To get started, you can install the Elastic Stack on a single VM or even on your laptop.

Implementing security is a critical step in setting up the Elastic Stack. To get up and running quickly with a sample installation, you skip those steps right now. Before sending sensitive data across the network, make sure you [secure the Elastic Stack](https://www.elastic.co/guide/en/elastic-stack-overview/6.6/elasticsearch-security.html) and enable [encrypted communications](https://www.elastic.co/guide/en/elastic-stack-overview/6.6/encrypting-communications.html).

## Before you begin

- See the [Elastic Support Matrix](https://www.elastic.co/support/matrix) for information about supported operating systems and product compatibility.
- Verify that your system meets the [minimum JVM requirements](https://www.elastic.co/support/matrix#matrix_jvm) for Logstash and Elasticsearch.

## Install Elasticsearch
[Elasticsearch](https://www.elastic.co/products/elasticsearch) is a real-time, distributed storage, search, and analytics engine. It can be used for many purposes, but one context where it excels is indexing streams of semi-structured data, such as logs or decoded network packets.

Elasticsearch can be run on your own hardware or using our hosted Elasticsearch Service on [Elastic Cloud](https://www.elastic.co/cloud), which is available on AWS and GCP. You can [try out the Elasticsearch Service](https://www.elastic.co/cloud/elasticsearch-service/signup) for free.

To download and install Elasticsearch, open a terminal window and use the commands that work with your system ([deb](https://www.elastic.co/guide/en/elastic-stack-get-started/current/get-started-elastic-stack.html#deb) for Debian/Ubuntu, [rom](https://www.elastic.co/guide/en/elastic-stack-get-started/current/get-started-elastic-stack.html#rpm) for Redhat/Centos/Fedora, [mac](https://www.elastic.co/guide/en/elastic-stack-get-started/current/get-started-elastic-stack.html#mac) for OS X, and [win](https://www.elastic.co/guide/en/elastic-stack-get-started/current/get-started-elastic-stack.html#win) for Windows):

**deb:**
```bash
curl -L -O https://artifacts.elastic.co/downloads/elasticsearch/elasticsearch-6.6.0.deb
sudo dpkg -i elasticsearch-6.6.0.deb
sudo /etc/init.d/elasticsearch start
```

**rpm:**
```bash
curl -L -O https://artifacts.elastic.co/downloads/elasticsearch/elasticsearch-6.6.0.rpm
sudo rpm -i elasticsearch-6.6.0.rpm
sudo service elasticsearch start
```

**mac:**
```bash
curl -L -O https://artifacts.elastic.co/downloads/elasticsearch/elasticsearch-6.6.0.tar.gz
tar -xzvf elasticsearch-6.6.0.tar.gz
cd elasticsearch-6.6.0
./bin/elasticsearch
```

**win:**

1. Download the Elasticsearch 6.6.0 Windows zip file from the [Elasticsearch download](https://www.elastic.co/downloads/elasticsearch) page.
2. Extract the contents of the zip file to a directory on your computer, for example, ```C:\Program Files```
3. Open a command prompt as an Administrator and navigate to the directory that contains the extracted files, for example:
    ```bash
    cd C:\Program Files\elasticsearch-6.6.0
    ```
4. Start Elasticsearch.

For other operating systems, go to the [Elasticsearch download](https://www.elastic.co/downloads/elasticsearch) page.

To learn more about installing, configuring, and running Elitesearch, read the [Elasticsearch Reference](https://www.elastic.co/downloads/elasticsearch).

## Make sure Elasticsearch is up and running
To test that the Elasticsearch daemon is up and running, try sending an HTTP GET request on port 9200.

```bash
curl http://127.0.0.1:9200
```
On Windows, if you don't have cURL installed, point your browser to the URL.

You should see a response similar to this:

```json
{
  "name" : "QtI5dUu",
  "cluster_name" : "elasticsearch",
  "cluster_uuid" : "DMXhqzzjTGqEtDlkaMOzlA",
  "version" : {
    "number" : "6.6.0",
    "build_flavor" : "default",
    "build_type" : "tar",
    "build_hash" : "00d8bc1",
    "build_date" : "2018-06-06T16:48:02.249996Z",
    "build_snapshot" : false,
    "lucene_version" : "7.3.1",
    "minimum_wire_compatibility_version" : "5.6.0",
    "minimum_index_compatibility_version" : "5.0.0"
  },
  "tagline" : "You Know, for Search"
}
```
## Install Kibana
[Kibana](https://www.elastic.co/products/kibana) is an open source analytics and visualization platform designed to work with Elasticsearch. You use Kibana to  search, view, and interact with data stored in Elasticsearch indices. You can easily perform advanced data analysis and visualize your data in a variety of charst, tables, and maps.

If you are running our hosted Elasticsearch Service on [Elastic Cloud](https://www.elastic.co/cloud), then [Kibana can be enabled](https://www.elastic.co/guide/en/cloud/current/ec-enable-kibana.html) with the flick of a switch.

We recommend that you install Kibana on the same server as Elasticsearch, but it is not required. If you install the products on different servers, you'll need to change the URL (IP:PORT) of the Elasticsearch server in the Kibana configuration file, ```kibana.yml```, before starting Kibana.

To download and install Kibana, open a terminal window and use the commands that work with your system:

**deb or rpm:**
```bash
curl -L -O https://artifacts.elastic.co/downloads/kibana/kibana-6.6.0-linux-x86_64.tar.gz
tar xzvf kibana-6.6.0-linux-x86_64.tar.gz
cd kibana-6.6.0-linux-x86_64/
./bin/kibana
```

**mac:**
```bash
curl -L -O https://artifacts.elastic.co/downloads/kibana/kibana-6.6.0-darwin-x86_64.tar.gz
tar xzvf kibana-6.6.0-darwin-x86_64.tar.gz
cd kibana-6.6.0-darwin-x86_64/
./bin/kibana
```

**win:**
1. Downwload the Kibana 6.6.0 Windows zip file from the [Kibana download](https://www.elastic.co/downloads/kibana) page.
2. Extract the contents of the zip file to a directory on your computer, for example, ```C:\Program Files```
3. Open a command prompt as an Administrator and navigate to the directory that contains the extracted files, for example:
```bash
cd C:\Program Files\kibana-6.6.0-windows
```
4. Start Kibana.
   
For other operating systems, go to the [Kibana download](https://www.elastic.co/downloads/kibana) page.

To learn more about installing, configuring, and running Kibana, read the [Kibana reference](https://www.elastic.co/guide/en/kibana/current/index.html).

## Launch the Kibana web interface
To launch the Kibana web interface, point your browser to port 5601. For example, http://127.0.0.1/5601.

## Install Beats
The Beats are open source data shippers that you install as agents on your servers to send operational data to Elasticsearch. Beats can send data directly to Elasticsearch or via Logstash, where you can further process and enhance the data.

Each Beat is a seperatly installable product. In this tutorial, your learn how to install and run Metricbeat with the ```system``` module enabled to collect system metrics.

To learn more about installing and configuring other Beats, see the Getting Started documentation:

| **Elastic Beats** | **To Capture** |
| ----------------- | -------------- |
| [Auditbeat](https://www.elastic.co/guide/en/beats/auditbeat/6.6/auditbeat-getting-started.html) | Audit data |
| [Filebeat](https://www.elastic.co/guide/en/beats/filebeat/6.6/filebeat-getting-started.html) | Log Files |
| [Functionbeat](https://www.elastic.co/guide/en/beats/functionbeat/6.6/functionbeat-getting-started.html) | Cloud Data |
| [Heartbeat](https://www.elastic.co/guide/en/beats/heartbeat/6.6/heartbeat-getting-started.html) | Availability monitoring |
| [Journalbeat](https://www.elastic.co/guide/en/beats/journalbeat/6.6/journalbeat-getting-started.html) | Systemd journals |
| [Metricbeat](https://www.elastic.co/guide/en/beats/metricbeat/6.6/metricbeat-getting-started.html) | Metrics |
| [Packetbeat](https://www.elastic.co/guide/en/beats/packetbeat/6.6/packetbeat-getting-started.html) | Network traffic |
| [Winlogbeat](https://www.elastic.co/guide/en/beats/winlogbeat/6.6/winlogbeat-getting-started.html) | Windows event logs |

## Install Metricbeat
To download and install Metricbeat, open a terminal window and use the command that work with your sytems:

**deb:**
```bash
curl -L -O https://artifacts.elastic.co/downloads/beats/metricbeat/metricbeat-6.6.0-amd64.deb
sudo dpkg -i metricbeat-6.6.0-amd64.deb
```
**rpm:**
```bash
curl -L -O https://artifacts.elastic.co/downloads/beats/metricbeat/metricbeat-6.6.0-x86_64.rpm
sudo rpm -vi metricbeat-6.6.0-x86_64.rpm
```

**mac:**
```bash
curl -L -O https://artifacts.elastic.co/downloads/beats/metricbeat/metricbeat-6.6.0-darwin-x86_64.tar.gz
tar xzvf metricbeat-6.6.0-darwin-x86_64.tar.gz
```

**win:**
1. Download the Metricbeat Windows zip file from the [Metricbeat download](https://www.elastic.co/downloads/beats/metricbeat) page.
2. Extract the contents of the zip file into ```C:\Program Files```.
3. Rename the ```metricbeat-6.6.0-windows``` directory to Metricbeat.
4. Open a PowerShell prompt as Administrator (right-click the PowerShell icon and select **Run As Administrator**).
5. From the PowerShell prompt, run the following commands to install Metricbeat as a Windows service:
```bash
PS > cd 'C:\Program Files\Metricbeat'
PS C:\Program Files\Metricbeat> .\install-service-metricbeat.ps1
```
If script execution is disabled on your system, set the execution policy for the current session to allow the script to run. For example ```PowerShell.exe -ExecutionPolicy UnRestricted -File .\install-service-metricbeat.ps1```.

For other operating systems, go to the [Beats download](https://www.elastic.co/downloads/beats) page.

## Ship system metrics to Elasticsearch
Metricbeat provides pre-built modules that you can use to rapidly implement and deploy a system monitoring solution, complete with sample dashboards and data visualizations, in about 5 minutes.

In this section, you learn how to run the ```system``` module to collect metrics from the operating sysstem and services running on your server. The system module collects system-level metrics, such as CPU usage, memory, file system, disk IO, and network IO statistics, as well as top-like statistics for every process running on your system.

**Before you begin**: Verify that Elasticsearch and Kibana are running and that Elasticsearch is ready to receive data from Metricbeat.