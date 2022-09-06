<script>

export default {
	name: "config_componant",
  data() {
    return {
      // Ros
      ros: null,
      xsens_config_pub: null,
      xsens_config_msg: null,
      xsens_status_sub: null,
      ntrip_config_pub: null,
      ntrip_config_msg: null,
      ntrip_status_sub: null,
      cam_config_pub: null,
      cam_config_msg: null,
      cam_status_sub: null,
      
      // Xsens config
      OutputConfigString: "",
      syncFunction: "Interval Transition Measurement [out] - 4",
      syncLine: "Out1 - 7",
      syncPolarity: "Positive Pulse - 1",
      syncTrigger: "Multiple times - 0",
      syncSkipFirst: 0,
      syncSkipFactor: 0,
      syncPulse: 10,
      syncDelay: 0,
      syncPerso: false,
      syncFromXsens: true,
      syncFromRPI: false,
      syncXsensFreq: 1,
      syncList: null,
      syncRPIFreq: 1,
      XsensPortName: "/dev/ttyS0",
      XsensBaudrate: 460800,
      wishGnsNP: true,
      wishPosPL: true,
      wishPosPA: true,
      wishOriOE: true,
      wishTmpIU: true,
      wishTmpIP: false,
      wishAccAA: true,
      wishAccAF: false,
      wishAngWR: true,
      wishAngWH: false,
      wishStaSW: true,
      GnsNP_freq: 2,
      PosPL_freq: 5,
      PosPA_freq: 5,
      OriOE_freq: 5,
      TmpIU_freq: 10,
      TmpIP_freq: 10,
      AccAA_freq: 10,
      AccAF_freq: 10,
      AngWR_freq: 10,
      AngWH_freq: 10,
      StaSW_freq: 10,
      PosPL_coor: "East-North-Up - e",
      PosPA_coor: "East-North-Up - e",
      OriOE_coor: "East-North-Up - e",
      AccAA_coor: "East-North-Up - e",
      AccAF_coor: "East-North-Up - e",
      AngWH_coor: "East-North-Up - e",
      AngWR_coor: "East-North-Up - e",
      PosPL_prec: "Fp1220 - a",
      PosPA_prec: "Fp1220 - a",
      OriOE_prec: "Fp1632 - b",
      AccAA_prec: "Fp1632 - b",
      AccAF_prec: "Fp1632 - b",
      AngWH_prec: "Fp1632 - b",
      AngWR_prec: "Fp1632 - b",
      
      // Xsens Status
      XsensStatus: "Deconnected",
      GnssFix: "0",
      RTKFix: "00",
      
      // Xsens data
      OriOE: {
      	"roll": 0,
      	"pitch": 0,
      	"yaw": 0
      },
      
      AttINS: {
      	"pitch": 0,
      	"roll": 0,
      	"yaw": 0
      },
      
      PosPL: {
      	"lat": 46.4621,
      	"lon": 6.88744
      },
      
      GnsNP: {
      	"lat": 46.4621,
      	"lon": 6.88744,
      	"alt": 400
      },
      
      PosINS: {
      	"lat": 46.4621,
      	"lon": 6.88744,
      	"alt": 400
      },
      
      // Ntrip Status
      NtripStatus: "Deconnected",
      RTCMStatus: "Deconnected",
      
      // Ntrip Config
      NtripPort: 5001,
      NtripHost: "193.134.218.96",
      NtripMount: "M_04",
      NtripUser: "Ecole01",
      NtripPassword: "365heig",
			NtripTime: 1,
    	NtripDist: 5,
    	RTCMPortName: "/dev/ttyUSB0",
    	RTCMBaudrate: 38400,
    	
    	// Cameras Config
    	CamSaveFolder: "/app/dev_ws/data/",
    	CamHeight: 2448,
    	CamWidth: 2048,
    	CamFrameRate: 1,
    	CamStream: true,
    	
    	
    	// Cameras status
    	CamStatus : "Deconnected",
    	
    	GnssFixLabel: "No GNSS",
    	RTKLabel: "No RTK",
    	status_style:{
    		"Inactive": "badge bg-secondary",
    		"Deconnected": "badge bg-dark",
    		"Active": "badge bg-success",
    		"Connected": "badge bg-success",
    		"Connecting": "badge bg-warning text-dark",
    		"Configuring": "badge bg-warning text-dark",
    		"Connecting RTCM": "badge bg-warning text-dark",
    		"Error": "badge bg-danger"
    	},
    	gnss_style:{
    	"0": "badge bg-danger",
    	"1": "badge bg-success",
    	},
    	
    	rtk_style:{
    	"00": "badge bg-danger",
    	"01": "badge bg-warning text-dark",
    	"10": "badge bg-success",
    	}
    }
  },
  
 
  methods: {
    connect: function() {
      this.ros = new ROSLIB.Ros({
        url : 'ws://192.168.43.166:9090'
      })
      this.ros.on('connection', function() {
        console.log('Connected to websocket server.');
      });

      this.ros.on('error', function(error) {
        console.log('Error connecting to websocket server: ', error);
      });

      this.ros.on('close', function() {
        console.log('Connection to websocket server closed.');
      });

    },
    
    // set Xsens configuration publisher
    setXsensConfigPublisher: function(){
      this.xsens_config_pub = new ROSLIB.Topic({
        ros : this.ros,
        name : 'config/xsens',
        messageType : 'xsens_msgs/ConfigXsens'
      })
    },
    
    // set Ntrip configuration publisher
    setNtripConfigPublisher: function(){
      this.ntrip_config_pub = new ROSLIB.Topic({
        ros : this.ros,
        name : 'config/ntripclient',
        messageType : 'xsens_msgs/ConfigNtrip'
      })
    },
    
    // set Cam configuration publisher
    setCamConfigPublisher: function(){
      this.cam_config_pub = new ROSLIB.Topic({
        ros : this.ros,
        name : 'config/camclient',
        messageType : 'xsens_msgs/ConfigCam'
      })
    },
    
    // set Xsens status subscriber
		setXsensStatusSubscriber: function(){
		  this.xsens_status_sub = new ROSLIB.Topic({
		    ros : this.ros,
		    name : 'mti/status',
		    messageType : 'xsens_msgs/StaSW'
		  })
			this.xsens_status_sub.subscribe(message => {
				this.XsensStatus = message.xsens_status
				this.GnssFix = message.gnss_fix
				if(this.GnssFix=='1'){this.GnssFixLabel = "GNSS OK"}
				else{this.GnssFixLabel = "No GNSS"}		
				this.RTKFix = message.rtk_status
				if(this.RTKFix=='00'){this.RTKLabel = "No RTK"}
				else if(this.RTKFix=='01'){this.RTKLabel = "RTK Floating"}
				else{this.RTKLabel = "RTK Fixed"}
			})
		},
		
		// set Xsens orientation Euler subscriber
		setXsensOriOESubscriber: function(){
		  this.xsens_OriOE_sub = new ROSLIB.Topic({
		    ros : this.ros,
		    name : 'mti/orientation_Euler',
		    messageType : 'xsens_msgs/OriOE'
		  })
			this.xsens_OriOE_sub.subscribe(message => {
				this.OriOE = message
			})
		},
	
		// set INS Attitude subscriber
		setAttINSSubscriber: function(){
		  this.AttINS_sub = new ROSLIB.Topic({
		    ros : this.ros,
		    name : 'central/attitude',
		    messageType : 'xsens_msgs/AttINS'
		  })
			this.AttINS_sub.subscribe(message => {
				this.AttINS.pitch = message.pitch
				this.AttINS.roll = message.roll
				this.AttINS.yaw = message.yaw
			})
		},

		// set Xsens position subscriber
		setXsensPosPLSubscriber : function(){
		  this.xsens_PosPL_sub = new ROSLIB.Topic({
		    ros : this.ros,
		    name : 'mti/position_lonLat',
		    messageType : 'xsens_msgs/PosPL'
		  })
			this.xsens_PosPL_sub.subscribe(message => {
				this.PosPL.lat = message.latitude
				this.PosPL.lon = message.longitude
			})
		},
	
		// set GNSS position subscriber
		setXsensGnsNPSubscriber: function(){
		  this.xsens_GnsNP_sub = new ROSLIB.Topic({
		    ros : this.ros,
		    name : 'mti/gnss_pvt_data',
		    messageType : 'xsens_msgs/GnsNP'
		  })
			this.xsens_GnsNP_sub.subscribe(message => {
				this.GnsNP.lat = message.lat
				this.GnsNP.lon = message.lon
				this.GnsNP.alt = message.height
			})
		},
		
		// set INS position subscriber
		setPosINSSubscriber: function(){
		  this.PosINS_sub = new ROSLIB.Topic({
		    ros : this.ros,
		    name : 'central/position',
		    messageType : 'xsens_msgs/PosINS'
		  })
			this.PosINS_sub.subscribe(message => {
				this.PosINS.lat = message.lat
				this.PosINS.lon = message.lon
				this.PosINS.alt = message.height
			})
		},
		
    // set Ntrip status subscriber
		setNtripStatusSubscriber: function(){
		  this.ntrip_status_sub = new ROSLIB.Topic({
		    ros : this.ros,
		    name : 'ntrip/status',
		    messageType : 'xsens_msgs/StaNT'
		  })
			this.ntrip_status_sub.subscribe(message => {
				this.NtripStatus = message.ntrip_status
				this.RTCMStatus = message.rtcm_status	
			})
		},
		
    // set Cam status subscriber
		setCamStatusSubscriber: function(){
		  this.cam_status_sub = new ROSLIB.Topic({
		    ros : this.ros,
		    name : 'cam/status',
		    messageType : 'xsens_msgs/StaCT'
		  })
			this.cam_status_sub.subscribe(message => {
				this.CamStatus = message.cam_status	
			})
		},

    // publish Xsens configuration
    publishXsensConfig: function(){
    	this.setXsensConfigPublisher()
    	this.setOutputConfig()
    	this.setSyncConfig()
    	this.xsens_config_msg = new ROSLIB.Message({
				output_config : this.OutputConfigString,
				baudrate : parseInt(this.XsensBaudrate),
				port_name : this.XsensPortName,
				sync_config : this.syncList,
				rtcm_refresh_dist : this.NtripDist,
				dt_freq: 1/this.syncRPIFreq,
			});
			this.xsens_config_pub.publish(this.xsens_config_msg)
    },
    
    // publish Ntrip configuration
    publishNtripConfig: function(){
    	this.setNtripConfigPublisher()
    	this.ntrip_config_msg = new ROSLIB.Message({
				host : this.NtripHost,
				port : this.NtripPort,
				mountpoint : this.NtripMount,
				username : this.NtripUser,
				password : this.NtripPassword,
				rtcm_timer : this.NtripTime,
				rtcm_port : this.RTCMPortName,
    		rtcm_baudrate : this.RTCMBaudrate,
			});
			this.ntrip_config_pub.publish(this.ntrip_config_msg)
    },
    
    // publish Cameras configuration
    publishCamConfig: function(){
    	this.setCamConfigPublisher()
    	this.cam_config_msg = new ROSLIB.Message({
				height : this.CamHeight,
				width : this.CamWidth,
				framerate : this.CamFrameRate,
				save_file : this.CamSaveFolder,
				stream : this.CamStream,
			});
			this.cam_config_pub.publish(this.cam_config_msg)
    },
		
		// compile output data string for Xsens - ajouter Donnée GNSS??
		setOutputConfig: function(){
			this.OutputConfigString=""
			if(this.wishOriOE){this.OutputConfigString=this.OutputConfigString + "oe" + this.OriOE_freq + this.OriOE_prec.slice(-1) + this.OriOE_coor.slice(-1) + ","}
			if(this.wishPosPL){this.OutputConfigString=this.OutputConfigString + "pl" + this.PosPL_freq + this.PosPL_prec.slice(-1) + this.PosPL_coor.slice(-1) + ","}
			if(this.wishPosPA){this.OutputConfigString=this.OutputConfigString + "pa" + this.PosPA_freq + this.PosPA_prec.slice(-1) + this.PosPA_coor.slice(-1) + ","}
			if(this.wishAccAA){this.OutputConfigString=this.OutputConfigString + "aa" + this.AccAA_freq + this.AccAA_prec.slice(-1) + this.AccAA_coor.slice(-1) + ","}
	    if(this.wishAccAF){this.OutputConfigString=this.OutputConfigString + "af" + this.AccAF_freq + this.AccAF_prec.slice(-1) + this.AccAF_coor.slice(-1) + ","}
	    if(this.wishTmpIU){this.OutputConfigString=this.OutputConfigString + "iu" + this.TmpIU_freq + ","}
	    if(this.wishTmpIP){this.OutputConfigString=this.OutputConfigString + "ip" + this.TmpIP_freq + ","}
	    if(this.wishGnsNP){this.OutputConfigString=this.OutputConfigString + "np" + this.GnsNP_freq + ","}
	    if(this.wishAngWR){this.OutputConfigString=this.OutputConfigString + "wr" + this.AngWR_freq + this.AngWR_prec.slice(-1) + this.AngWR_coor.slice(-1) + ","}
	    if(this.wishAngWH){this.OutputConfigString=this.OutputConfigString + "wh" + this.AngWH_freq + this.AngWH_prec.slice(-1) + this.AngWH_coor.slice(-1) + ","}
	    if(this.wishStaSW){this.OutputConfigString=this.OutputConfigString + "sw" + this.StaSW_freq + ","}
			this.OutputConfigString = this.OutputConfigString.slice(0, -1)
		},
    
    // compile Xsens synchronisation setting list
    setSyncConfig: function() {
    	this.syncList = []
    	this.syncList.push(parseInt(this.syncFunction.slice(-2)))
    	this.syncList.push(parseInt(this.syncLine.slice(-1)))
    	this.syncList.push(parseInt(this.syncPolarity.slice(-1)))
    	this.syncList.push(parseInt(this.syncTrigger.slice(-1)))
    	this.syncList.push(this.syncSkipFirst)
    	if (this.syncFromXsens) {this.syncList.push(parseInt(399/this.syncXsensFreq))}
    	else {this.syncList.push(this.syncSkipFactor)}
    	this.syncList.push(this.syncPulse)
    	this.syncList.push(this.syncDelay)
    }, 
    
    // set default config to trigger from Raspberry
    configTrigRPI: function() {
      this.syncFunction = "Trigger Indication [in] - 3"
      this.syncLine = "In1 - 2"
      this.syncPolarity = "Positive Pulse - 1"
      this.syncTrigger = "Multiple times - 0"
      this.syncSkipFirst = 0
      this.syncSkipFactor = 0
      this.syncPulse = 10
      this.syncDelay = 0
      this.syncPerso = false
      this.syncFromRPI = true
      this.syncFromXsens = false
  	},
  	
  	// set default config to trigger from Xsens
    configTrigXsens: function() {
      this.syncFunction = "Interval Transition Measurement [out] - 4"
      this.syncLine = "Out1 - 7"
      this.syncPolarity = "Positive Pulse - 1"
      this.syncTrigger = "Multiple times - 0"
      this.syncSkipFirst = 0
      this.syncSkipFactor = 0
      this.syncPulse = 10
      this.syncDelay = 0
      this.syncPerso = false
      this.syncFromRPI = false
      this.syncFromXsens = true
  	},
  	
  	plotOriOE: function(){
  		
  		var roll = {
				y: [this.OriOE.roll],
				mode: 'lines',
				name: 'roll',
				line: {
					color: 'rgb(0, 204, 0)',
					width: 3
				}
			};
  		var pitch = {
				y: [this.OriOE.pitch],
				mode: 'lines',
				name: 'pitch',
				line: {
					color: 'rgb(0, 128, 255)',
					width: 3
				}
			};	
  		var yaw = {
				y: [this.OriOE.yaw],
				mode: 'lines',
				name: 'yaw',
				line: {
					color: 'rgb(255, 51, 51)',
					width: 3
				}
			};
			
			var roll_INS = {
				y: [this.AttINS.roll],
				mode: 'lines',
				name: 'roll',
				line: {
					color: 'rgb(0, 204, 0)',
					dash: 'dash',
					width: 3
				}
			};
  		var pitch_INS = {
				y: [this.AttINS.pitch],
				mode: 'lines',
				name: 'pitch',
				line: {
					color: 'rgb(0, 128, 255)',
					dash: 'dash',
					width: 3
				}
			};	
  		var yaw_INS = {
				y: [this.AttINS.yaw],
				mode: 'lines',
				name: 'yaw',
				line: {
					color: 'rgb(255, 51, 51)',
					dash: 'dash',
					width: 3
				}
			};
			
			var layout = {
				title:{text:'Orientation Euler', xref: 'paper', x :0.01},
				xaxis: {title: {text: 'Data packages'}},
				yaxis: {title: {text: 'Orientation [deg]'}},
				xaxis: {range: [0,200]},
				yaxis: {range: [-180,180]}
				}
			
			var data = [roll, pitch, yaw, roll_INS, pitch_INS, yaw_INS];

  		Plotly.plot('plot1', data, layout);
  	},
  	
  	StartPlotOriOE: function(){	  		
			var cnt1 = 0;
			setInterval(()=>{
				Plotly.extendTraces('plot1',{y:[[this.OriOE.roll],[this.OriOE.pitch],[this.OriOE.yaw],[(180/3.14159265)*this.AttINS.roll],[(180/3.14159265)*this.AttINS.pitch],[(180/3.14159265)*this.AttINS.yaw]]}, [0,1,2,3,4,5]);
				cnt1++;
				if(cnt1 > 200) {
					Plotly.relayout('plot1',{
						xaxis: {
							range: [cnt1-200,cnt1]
						}
					});
				}
			},100);
  	},
  	
  	
		plotPath: function(){
  		
  		var path_xsens = {
				x: [this.PosPL.lon],
				y: [this.PosPL.lat],
				mode: 'lines',
				name: 'path_xsens',
				line: {
					color: 'rgb(255, 0, 0)',
					dash: 'solid',
					width: 2
				}
			};
			
			var path_INS = {
				x: [this.PosINS.lon],
				y: [this.PosINS.lat],
				mode: 'lines',
				name: 'path_xsens',
				line: {
					color: 'rgb(0, 0, 0)',
					dash: 'dash',
					width: 2
				}
			};
			
			var path_GNSS = {
				x: [this.GnsNP.lon],
				y: [this.GnsNP.lat],
				mode: 'markers',
				name: 'path_GNSS',
				marker: {
					symbol: "cross-dot",
					color: 'rgb(0, 0, 0)',
					size: 8
				}
			};
			
			var layout = {
				title:{text:'Path', xref: 'paper', x :0.01},
				xaxis: {title: {text: 'Longitude [deg]'}},
				yaxis: {title: {text: 'Latitude [deg]'}},
				autosize: false,
				width: 900,
				height: 800,
				}
			
			var data = [path_xsens, path_GNSS, path_INS];
		

  		Plotly.plot('plot2', data, layout);
  	},
  	
  	
  	StartPlotPath: function(){	  		
			setInterval(()=>{
				Plotly.extendTraces('plot2',{x: [[this.PosPL.lon],[this.GnsNP.lon],[this.PosINS.lon]], y:[[this.PosPL.lat],[this.GnsNP.lat],[this.PosINS.lat]]}, [0,1,2],500);
				//Plotly.relayout('plot2',{xaxis: {range: [this.PosPL.lon-0.00001,this.PosPL.lon+0.00001]},yaxis: {range: [this.PosPL.lat-0.00001,this.PosPL.lat+0.00001]}});
				Plotly.relayout('plot2',{xaxis: {range: [this.PosPL.lon-0.00005,this.PosPL.lon+0.00005]},yaxis: {range: [this.PosPL.lat-0.00005,this.PosPL.lat+0.00005]}});
			},100);
  	},
  	
  	configTrigPerso: function() {
  		this.syncPerso = true
  		this.syncFromXsens = false
  		this.syncFromRPI = false
  	}
  },

  mounted() {
   try {
      this.connect();
      this.setXsensStatusSubscriber();
			this.setNtripStatusSubscriber();
			this.setCamStatusSubscriber();
			this.setXsensOriOESubscriber();
			this.setXsensPosPLSubscriber();
			this.setXsensGnsNPSubscriber();
			this.setPosINSSubscriber();
			this.setAttINSSubscriber();
			this.plotOriOE();
			this.plotPath();
    } catch (error) {
      console.error(error);
    }
  }
}
</script>

<template>
<nav class="navbar fixed-top navbar-light" style="background-color: #e3e3e3;">
  <div class="container-fluid">
		<div class="row">
		  <div class="col">
		    <h5><span v-bind:class="status_style[XsensStatus]">Xsens {{this.XsensStatus}}</span></h5>
		  </div>
		  <div class="col">
		    <h5><span v-bind:class="status_style[NtripStatus]">ntrip {{this.NtripStatus}}</span></h5>
		  </div>
		  <div class="col">
		    <h5><span v-bind:class="status_style[RTCMStatus]">RTCM {{this.RTCMStatus}}</span></h5>
		  </div>
		  <div class="col">
		    <h5><span v-bind:class="status_style[CamStatus]">Cameras {{this.CamStatus}}</span></h5>
		  </div>
		  <div class="col">
		    <h5><span v-bind:class="gnss_style[GnssFix]">{{GnssFixLabel}}</span></h5>
		  </div>
		  <div class="col">
		    <h5><span v-bind:class="rtk_style[RTKFix]">{{RTKLabel}}</span></h5>
		  </div>
  	</div>
  </div>
</nav>


<h1 class="display-6">Measurments</h1>
<p></p>
<button class="btn btn-primary" type="button" @click="StartPlotOriOE">Start plot orientation</button>
<div ref="plot1" id="plot1"></div>
<p></p>
<button class="btn btn-primary" type="button" @click="StartPlotPath">Start plot path</button>
<div ref="plot2" id="plot2"></div>


<h1 class="display-6">Configuration</h1>
<p></p>
<div class="accordion" id="accordionExample">
  <div class="accordion-item">
    <h2 class="accordion-header" id="headingOne">
      <button class="accordion-button" type="button" data-bs-toggle="collapse" data-bs-target="#collapseOne" aria-expanded="false" aria-controls="collapseOne">
        <strong>CONFIGURATION NTRIP</strong>
      </button>
    </h2>
    <div id="collapseOne" class="accordion-collapse collapse" aria-labelledby="headingOne" data-bs-parent="#accordionExample">
      <div class="accordion-body">
      
      <table class="table table-sm table-borderless">
		    	<thead>
						<tr class="table-secondary">
							<th scope="col" colspan="3">CONNECTION SERVEUR NTRIP</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td>
								<label class="form-label">Username</label>
								<input class="form-control form-control-sm" type="text" v-model="NtripUser">
							</td>
							<td>
								<label class="form-label">Password</label>
								<input class="form-control form-control-sm" type="password" v-model="NtripPassword">
							</td>
							<td>
								<label class="form-label">Host</label>
								<input class="form-control form-control-sm" type="text" v-model="NtripHost">
							</td>
						</tr>
						<tr>
							<td>
								<label class="form-label">Port</label>
								<input class="form-control form-control-sm" type="text" v-model="NtripPort">
							</td>
							<td>
								<label class="form-label">Mountpoint</label>
								<input class="form-control form-control-sm" type="text" v-model="NtripMount"><p></p>
							</td>
						</tr>
						<tr>
							<th class="table-secondary" colspan="3">RTCM PARAMETER</th>
						</tr>
						<tr>
							<td>
								<label class="form-label">Port</label>
								<input class="form-control form-control-sm" type="text" v-model="RTCMPortName">
							</td>
							<td>
								<label class="form-label">Baudrate</label>
								<input class="form-control form-control-sm" type="text" v-model="RTCMBaudrate">
							</td>
							<td>
								<label class="form-label">RTCM refresh rate [s]</label>
								<input type="number" class="form-control form-control-sm" style="width: 13em" v-model="NtripTime">
							</td>
						</tr>
					</tbody>
				</table>
      
      
    	</div>
  	</div>
  </div>
  <div class="accordion-item">
    <h2 class="accordion-header" id="headingTwo">
      <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#collapseTwo" aria-expanded="false" aria-controls="collapseTwo">
        <strong>CONFIGURATION XSENS</strong>
      </button>
    </h2>
    <div id="collapseTwo" class="accordion-collapse collapse" aria-labelledby="headingTwo" data-bs-parent="#accordionExample">
      <div class="accordion-body">
      	
      	<table class="table table-sm table-borderless">
		    	<thead>
						<tr class="table-secondary">
							<th scope="col" colspan="2">CONNECTION</th>
							<th scope="col" colspan="1">PARAMETER</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td>
								<label class="form-label">Port</label>
								<input class="form-control form-control-sm" type="text" v-model="XsensPortName">
							</td>
							<td>
								<label class="form-label">Baudrate</label>
								<select class="form-select form-select-sm" v-model="XsensBaudrate">
									<option>4800</option>
									<option>9600</option>
									<option>14400</option>
									<option>19200</option>
									<option>28800</option>
									<option>38400</option>
									<option>57600</option>
									<option>76600</option>
									<option>115200</option>
									<option>230400</option>
									<option>460800</option>
									<option>921600</option>
								</select>
							</td>
							<td>
								<label class="form-label">RTCM refresh distance [m]</label>
								<input type="number" class="form-control form-control-sm" style="width: 13em" v-model="NtripDist">
							</td>
						</tr>
					</tbody>
				</table>
      	
      	<table class="table table-sm table-borderless">
		    	<thead>
						<tr class="table-secondary">
							<th scope="col" colspan="3">SYNCHRONISATION</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td>
								<div class="form-check">
									<input class="form-check-input" type="radio" name="flexRadioDefault" id="flexRadioDefault1" v-on:change="configTrigRPI()">
									<label class="form-check-label" for="flexRadioDefault1">
										Trigger form Raspberry - Default config
									</label>
									<div class="input-group input-group-sm mb-3" style="width: 7em">
										<input type="number" class="form-control"  v-model="syncRPIFreq" :disabled="!syncFromRPI">
										<div class="input-group-append">
											<span class="input-group-text" id="inputGroup-sizing-sm"> hz </span>
										</div>
									</div>
								</div>
							</td>
							<td>
								<div class="form-check">
									<input class="form-check-input" type="radio" name="flexRadioDefault" id="flexRadioDefault2" v-on:change="configTrigXsens()" checked>
									<label class="form-check-label" for="flexRadioDefault2">
										Trigger form Xsens - Default config
									</label>
									<div class="input-group input-group-sm mb-3" style="width: 7em">
										<input type="number" class="form-control"  v-model="syncXsensFreq" :disabled="!syncFromXsens">
										<div class="input-group-append">
											<span class="input-group-text" id="inputGroup-sizing-sm"> hz </span>
										</div>
									</div>
								</div>
							</td>
							<td>
								<div class="form-check">
									<input class="form-check-input" type="radio" name="flexRadioDefault" id="flexRadioDefault3" v-on:change="configTrigPerso()">
									<label class="form-check-label" for="flexRadioDefault3">
										Custom
									</label>
								</div>
							</td>
						</tr>
				  	<tr>
				  		<td colspan="3">
							<div class="row">
								<div class="col">
									<label class="form-label">Function</label>
									<select class="form-select form-select-sm" v-model="syncFunction" :disabled="!syncPerso">
										<option>Trigger Indication [in] - 3</option>
										<option>Send Latest [in] - 8</option>
										<option>Start Sampling [in] - 11</option>
										<option>Clock Bias Estimation [in] - 9</option>
										<option>Interval Transition Measurement [out] - 4</option>
									</select>
								</div>
								<div class="col">
									<label class="form-label">Line</label>
									<select class="form-select form-select-sm" v-model="syncLine" :disabled="!syncPerso">
										<option>In1 - 2</option>
										<option>In2 - 9</option>
										<option>ReqData - 6</option>
										<option>Out1 - 7</option>
									</select>
								</div>
								<div class="col">
									<label class="form-label">Polarity</label>
									<select class="form-select form-select-sm" v-model="syncPolarity" :disabled="!syncPerso">
										<option>Positive Pulse - 1</option>
										<option>Negative Pulse - 2</option>
										<option>Both/Toggle - 3</option>
										<option>Sync disable - 0</option>
									</select>
								</div>
								<div class="col">
									<label class="form-label">Trigger Once</label>
									<select class="form-select form-select-sm" v-model="syncTrigger" :disabled="!syncPerso">
										<option>Only once - 1</option>
										<option>Multiple times - 0</option>
									</select>
								</div>
							</div>
							<p></p>
							<div class="row">
								<div class="col">
									<label class="form-label">Skip First</label>
									<input type="number" class="form-control form-control-sm" v-model="syncSkipFirst" :disabled="!syncPerso">
								</div>
								<div class="col">
									<label class="form-label">Skip Factor</label>
									<input type="number" class="form-control form-control-sm" v-model="syncSkipFactor" :disabled="!syncPerso">
								</div>
								<div class="col">
									<label class="form-label">Pulse Width [100μs]</label>
									<input type="number" class="form-control form-control-sm" v-model="syncPulse" :disabled="!syncPerso">
								</div>
								<div class="col">
									<label class="form-label">Delay [100μs] in [-30000..+30000]</label>
									<input type="number" class="form-control form-control-sm" v-model="syncDelay" :disabled="!syncPerso">
								</div>
							</div>
							</td>
						</tr>
					</tbody>
				</table>
				
      	<p></p>
      	<table class="table table-sm table-borderless">
					<thead>
						<tr class="table-secondary">
							<th scope="col" colspan="5">OUTPUT DATA</th>
						</tr>
					</thead>
					<thead>
						<tr class="table-secondary">
							<th scope="col">Group</th>
							<th scope="col">Type</th>
							<th scope="col">Frequency [hz]</th>
							<th scope="col">Precision</th>
							<th scope="col">Coordinate system</th>
						</tr>
					</thead>
					<tbody>
						<th scope="row">Positions</th>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishPosPL">
							</th>
							<td>Latitude / Longitude</td>
							<td>
						  	<input type="number" v-model="PosPL_freq" style="width: 5em"><label>&nbspmax 400 hz</label>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="PosPL_prec">
										<option>Float32 - f</option>
										<option>Float64 - d</option>
										<option>Fp1220 - a</option>
										<option>Fp1632 - b</option>
									</select>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="PosPL_coor">
										<option>East-North-Up - e</option>
										<option>North-East-Down - n</option>
										<option>North-West-Up - w</option>
									</select>
							</td>
						</tr>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishPosPA">
							</th>
							<td>Altitude ellipsoïdale</td>
							<td>
								<input type="number" v-model="PosPA_freq" style="width: 5em"><label>&nbspmax 400 hz</label>
							</td>
						 	<td>
									<select class="form-select form-select-sm" v-model="PosPA_prec">
										<option>Float32 - f</option>
										<option>Float64 - d</option>
										<option>Fp1220 - a</option>
										<option>Fp1632 - b</option>
									</select>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="PosPA_coor">
										<option>East-North-Up - e</option>
										<option>North-East-Down - n</option>
										<option>North-West-Up - w</option>
									</select>
							</td>
						</tr>
						
						
						<th scope="row">GNSS</th>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishGnsNP">
							</th>
							<td>GNSS PVT data</td>
							<td>
								<input type="number" v-model="GnsNP_freq" style="width: 5em"><label>&nbspmax 4 hz</label>
							</td>
						</tr>
						
						
						<th scope="row">Orientation</th>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishOriOE">
							</th>
							<td>Roll / Pitch / Yaw</td>
							<td>
								<input type="number" v-model="OriOE_freq" style="width: 5em"><label>&nbspmax 400 hz</label>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="OriOE_prec">
										<option>Float32 - f</option>
										<option>Float64 - d</option>
										<option>Fp1220 - a</option>
										<option>Fp1632 - b</option>
									</select>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="OriOE_coor">
										<option>East-North-Up - e</option>
										<option>North-East-Down - n</option>
										<option>North-West-Up - w</option>
									</select>
							</td>
						</tr>
						<th scope="row">Acceleration</th>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishAccAA">
							</th>
							<td>Acceleration</td>
							<td>
								<input type="number" v-model="AccAA_freq" style="width: 5em"><label>&nbspmax 2000 hz</label>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="AccAA_prec">
										<option>Float32 - f</option>
										<option>Float64 - d</option>
										<option>Fp1220 - a</option>
										<option>Fp1632 - b</option>
									</select>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="AccAA_coor">
										<option>East-North-Up - e</option>
										<option>North-East-Down - n</option>
										<option>North-West-Up - w</option>
									</select>
							</td>
						</tr>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishAccAF">
							</th>
							<td>Free acceleration</td>
							<td>
								<input type="number" v-model="AccAF_freq" style="width: 5em"><label>&nbspmax 2000 hz</label>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="AccAF_prec">
										<option>Float32 - f</option>
										<option>Float64 - d</option>
										<option>Fp1220 - a</option>
										<option>Fp1632 - b</option>
									</select>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="AccAF_coor">
										<option>East-North-Up - e</option>
										<option>North-East-Down - n</option>
										<option>North-West-Up - w</option>
									</select>
							</td>
						</tr>
						<th scope="row">Angular velocity</th>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishAngWR">
							</th>
							<td>Rate of turn</td>
							<td>
								<input type="number" v-model="AngWR_freq" style="width: 5em"><label>&nbspmax 2000 hz</label>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="AngWR_prec">
										<option>Float32 - f</option>
										<option>Float64 - d</option>
										<option>Fp1220 - a</option>
										<option>Fp1632 - b</option>
									</select>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="AngWR_coor">
										<option>East-North-Up - e</option>
										<option>North-East-Down - n</option>
										<option>North-West-Up - w</option>
									</select>
							</td>
						</tr>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishAngWH">
							</th>
							<td>Rate of turn HR</td>
							<td>
								<input type="number" v-model="AngWH_freq" style="width: 5em"><label>&nbspmax 2000 hz</label>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="AngWH_prec">
										<option>Float32 - f</option>
										<option>Float64 - d</option>
										<option>Fp1220 - a</option>
										<option>Fp1632 - b</option>
									</select>
							</td>
							<td>
									<select class="form-select form-select-sm" v-model="AngWH_coor">
										<option>East-North-Up - e</option>
										<option>North-East-Down - n</option>
										<option>North-West-Up - w</option>
									</select>
							</td>
						</tr>
						<th scope="row">Timestamp</th>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishTmpIU">
							</th>
							<td>UTC time</td>
							<td>
								<input type="number" v-model="TmpIU_freq" style="width: 5em"><label>&nbspmax 2000 hz</label>
							</td>
						</tr>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishTmpIP">
							</th>
							<td>Packet counter</td>
							<td>
								<input type="number" v-model="TmpIP_freq" style="width: 5em"><label>&nbspmax 2000 hz</label>
							</td>
						</tr>
						<th scope="row">Status</th>
						<tr>
							<th scope="row">
								<input class="form-check-input" type="checkbox" v-model="wishStaSW">
							</th>
							<td>Status word</td>
							<td>
								<input type="number" v-model="StaSW_freq" style="width: 5em"><label>&nbspmax 2000 hz</label>
							</td>
						</tr>
					</tbody>
				</table>	
      </div>
    </div>
  </div>
	<div class="accordion-item">
    <h2 class="accordion-header" id="headingThree">
      <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#collapseThree" aria-expanded="false" aria-controls="collapseThree">
        <strong>CONFIGURATION CAMERAS</strong>
      </button>
    </h2>
    <div id="collapseThree" class="accordion-collapse collapse" aria-labelledby="headingThree" data-bs-parent="#accordionExample">
      <div class="accordion-body">
				
				<table class="table table-sm table-borderless">
					<tbody>
						<tr>
							<td>
								<label class="form-label">Image height [px]</label>
								<input type="number" class="form-control form-control-sm" style="width: 13em" v-model="CamHeight">
							</td>
							<td>
								<label class="form-label">Image width [px]</label>
								<input type="number" class="form-control form-control-sm" style="width: 13em" v-model="CamWidth">
							</td>
							<td>
								<label class="form-label">Framerate [img/sec]</label>
								<input type="number" class="form-control form-control-sm" style="width: 13em" v-model="CamFrameRate">
							</td>
							<td>
								<label class="form-label"> Save images in...</label>
								<input class="form-control form-control-sm" type="text" v-model="CamSaveFolder" style="width: 20em">
							</td>
							<td>
								<input class="form-check-input" type="checkbox" v-model="CamStream">
								<label class="form-label"> Stream pictures</label>
							</td>
						</tr>
					</tbody>
				</table>
				
				
				<p></p>
				<table class="table table-sm table-borderless">
		    	<thead>
						<tr class="table-secondary">
							<th scope="col" colspan="1">Camera 1</th>
							<th scope="col" colspan="1">Camera 2</th>
							<th scope="col" colspan="1">Camera 3</th>
							<th scope="col" colspan="1">Camera 4</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td>
								<label class="form-label">Dedicated parameters ?</label>
							</td>
							<td>
								<label class="form-label">Dedicated parameters ?</label>
							</td>
							<td>
								<label class="form-label">Dedicated parameters ?</label>
							</td>
							<td>
								<label class="form-label">Dedicated parameters ?</label>
							</td>
						</tr>
					</tbody>
				</table>
      </div>
    </div>
  </div>
</div>
<p></p>
	<div class="d-grid gap-2 col-4 mx-auto">
		<button class="btn btn-primary" type="button" @click="publishNtripConfig">Load Ntrip Configuration</button>
		<button class="btn btn-primary" type="button" @click="publishCamConfig">Load Cameras Configuration</button>
		<button class="btn btn-primary" type="button" @click="publishXsensConfig">Load Xsens Configuration</button>
	</div>
</template> 


