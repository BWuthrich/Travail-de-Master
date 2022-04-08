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
      syncXsensFreq: 1,
      syncList: null,
      XsensPortName: "/dev/ttyS0",
      XsensBaudrate: 115200,
      wishPosPL: true,
      wishPosPA: true,
      wishOriOE: true,
      wishTmpIU: true,
      wishTmpIP: true,
      wishAccAA: false,
      wishAccAF: false,
      wishAngWR: false,
      wishAngWH: false,
      wishStaSW: true,
      PosPL_freq: 30,
      PosPA_freq: 30,
      OriOE_freq: 30,
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
      
      boolshit: false,
      
      // Xsens Status
      XsensStatus: "Deconnected",
      GnssFix: "0",
      
      // Ntrip Status
      NtripStatus: "Deconnected",
      
      // Ntrip Config
      NtripPort: 5001,
      NtripHost: "193.134.218.96",
      NtripMount: "M_04",
      NtripUser: "Ecole01",
      NtripPassword: "365heig",
			NtripTime: 3,
    	NtripDist: 5,
    	
    	status_style:{
    		"Inactive": "badge bg-secondary",
    		"Deconnected": "badge bg-dark",
    		"Active": "badge bg-success",
    		"Connecting": "badge bg-warning text-dark",
    		"Configuring": "badge bg-warning text-dark",
    		"Connecting RTCM": "badge bg-warning text-dark"
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
				console.log("Xsens:" +this.XsensStatus)			
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
				console.log("Ntrip:" +this.NtripStatus)		
			})
		},

    // publish Xsens configuration
    publishXsensConfig: function(){
    	this.setXsensConfigPublisher()
    	this.setOutputConfig()
    	this.setSyncConfig()
    	this.xsens_config_msg = new ROSLIB.Message({
				output_config : this.OutputConfigString,
				baudrate : this.XsensBaudrate,
				port_name : this.XsensPortName,
				sync_config : this.syncList,
				rtcm_refresh_dist : this.NtripDist,
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
			});
			console.log(this.ntrip_config_msg)
			this.ntrip_config_pub.publish(this.ntrip_config_msg)
    },
		
		// compile output data string for Xsens Donnée GNSS?? // status byte pour legerté??
		setOutputConfig: function(){
			this.OutputConfigString=""
			if(this.wishOriOE){this.OutputConfigString=this.OutputConfigString + "oe" + this.OriOE_freq + this.OriOE_prec.slice(-1) + this.OriOE_coor.slice(-1) + ","}
			if(this.wishPosPL){this.OutputConfigString=this.OutputConfigString + "pl" + this.PosPL_freq + this.PosPL_prec.slice(-1) + this.PosPL_coor.slice(-1) + ","}
			if(this.wishPosPA){this.OutputConfigString=this.OutputConfigString + "pa" + this.PosPA_freq + this.PosPA_prec.slice(-1) + this.PosPA_coor.slice(-1) + ","}
			if(this.wishAccAA){this.OutputConfigString=this.OutputConfigString + "aa" + this.AccAA_freq + this.AccAA_prec.slice(-1) + this.AccAA_coor.slice(-1) + ","}
	    if(this.wishAccAF){this.OutputConfigString=this.OutputConfigString + "af" + this.AccAF_freq + this.AccAF_prec.slice(-1) + this.AccAF_coor.slice(-1) + ","}
	    if(this.wishTmpIU){this.OutputConfigString=this.OutputConfigString + "iu" + this.TmpIU_freq + ","}
	    if(this.wishTmpIP){this.OutputConfigString=this.OutputConfigString + "ip" + this.TmpIP_freq + ","}
	    if(this.wishAngWR){this.OutputConfigString=this.OutputConfigString + "wr" + this.AngWR_freq + this.AngWR_prec.slice(-1) + this.AngWR_coor.slice(-1) + ","}
	    if(this.wishAngWH){this.OutputConfigString=this.OutputConfigString + "wh" + this.AngWH_freq + this.AngWH_prec.slice(-1) + this.AngWH_coor.slice(-1) + ","}
	    if(this.wishStaSW){this.OutputConfigString=this.OutputConfigString + "sw" + this.StaSW_freq + ","}
			this.OutputConfigString = this.OutputConfigString.slice(0, -1)
		},
    
    // compile synchronisation setting list
    setSyncConfig: function() {
    	this.syncList = []
    	this.syncList.push(parseInt(this.syncFunction.slice(-2)))
    	this.syncList.push(parseInt(this.syncLine.slice(-1)))
    	this.syncList.push(parseInt(this.syncPolarity.slice(-1)))
    	this.syncList.push(parseInt(this.syncTrigger.slice(-1)))
    	this.syncList.push(this.syncSkipFirst)
    	if (this.syncFromXsens) {this.syncList.push(parseInt(399*this.syncXsensFreq))}
    	else {this.syncList.push(this.syncSkipFactor)}
    	this.syncList.push(this.syncPulse)
    	this.syncList.push(this.syncDelay)
    }, 
    
    // set default config to trigger from Raspberry
    configTrigRPI: function() {
      this.syncFunction = "Send Latest [in] - 8"
      this.syncLine = "In1 - 2"
      this.syncPolarity = "Positive Pulse - 1"
      this.syncTrigger = "Multiple times - 0"
      this.syncSkipFirst = 0
      this.syncSkipFactor = 0
      this.syncPulse = 10
      this.syncDelay = 0
      this.syncPerso = false
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
      this.syncFromXsens = true
  	},
  	
  	configTrigPerso: function() {
  		this.syncPerso = true
  		this.syncFromXsens = false
  	}
  },

  mounted() {
   try {
      this.connect();
      this.setXsensStatusSubscriber();
			this.setNtripStatusSubscriber();
    } catch (error) {
      console.error(error);
    }
  }
}
</script>

<template>
<nav class="navbar fixed-top navbar-light" style="background-color: #e3e3e3;">
  <div class="container-fluid">
		<h5><span v-bind:class="status_style[XsensStatus]">Xsens {{this.XsensStatus}}</span></h5>
		<h5><span v-bind:class="status_style[NtripStatus]">ntrip {{this.NtripStatus}}</span></h5>
		<h5><span class="badge bg-danger" v-if="GnssFix=='0'">No GNSS</span></h5>
		<h5><span class="badge bg-success" v-if="GnssFix=='1'">GNSS OK</span></h5>
  </div>
</nav>
  
<div class="accordion" id="accordionExample">
  <div class="accordion-item">
    <h2 class="accordion-header" id="headingOne">
      <button class="accordion-button" type="button" data-bs-toggle="collapse" data-bs-target="#collapseOne" aria-expanded="true" aria-controls="collapseOne">
        <strong>CONFIGURATION NTRIP</strong>
      </button>
    </h2>
    <div id="collapseOne" class="accordion-collapse collapse show" aria-labelledby="headingOne" data-bs-parent="#accordionExample">
      <div class="accordion-body">
      
      <table class="table table-sm table-borderless">
		    	<thead>
						<tr class="table-secondary">
							<th scope="col" colspan="3">CONNECTION</th>
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
							<th class="table-secondary" colspan="3">PARAMETER</th>
						</tr>
						<tr>
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
								<input class="form-control form-control-sm" type="text" v-model="XsensBaudrate">
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
								</div>
							</td>
							<td>
								<div class="form-check">
									<input class="form-check-input" type="radio" name="flexRadioDefault" id="flexRadioDefault2" v-on:change="configTrigXsens()" checked>
									<label class="form-check-label" for="flexRadioDefault2">
										Trigger form Xsens - Default config
									</label>
									<input type="number" class="form-control form-control-sm" style="width: 13em" v-model="syncXsensFreq" placeholder="trigger frequency [hz]" :disabled="!syncFromXsens">
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
        ...
      </button>
    </h2>
    <div id="collapseThree" class="accordion-collapse collapse" aria-labelledby="headingThree" data-bs-parent="#accordionExample">
      <div class="accordion-body">BLABLA...
      </div>
    </div>
  </div>
</div>
<p></p>
	<div class="d-grid gap-2 col-4 mx-auto">
		<button class="btn btn-primary" type="button" @click="publishNtripConfig" v-if="XsensStatus!=='Configuring' && XsensStatus!=='Connecting'">Change Ntrip Configuration</button>
		<button class="btn btn-primary" type="button" @click="publishXsensConfig" v-if="NtripStatus=='Active'">Change Xsens Configuration</button>
	</div>
</template>


