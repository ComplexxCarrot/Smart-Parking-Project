
    var config = {
        apiKey: "AIzaSyA8FnmWkdtP-lCCeZwnCOxWgnP0txHPp-U",
        authDomain: "carrotkun-smart-parking.firebaseapp.com",
        projectId: "carrotkun-smart-parking",
        storageBucket: "carrotkun-smart-parking.appspot.com",
        messagingSenderId: "882930562235",
        appId: "1:882930562235:web:ffd3e342ddd1404f53e59e",
        databaseURL: "https://carrotkun-smart-parking-default-rtdb.asia-southeast1.firebasedatabase.app",
    };
    firebase.initializeApp(config);
    database = firebase.database();

    var res = database.on('Parking slot available');
    res.on('value', gotData);

    function gotData(data){
      console.log(data.val());
    }
    //var result = document.getElementByID('result');
    //var dbRefObject = firebase.database().ref().child('Parking slot available');
    //dbRefObject.on('value', snap => result.innerText = snap.val());

    //var ps1= document.getElementByID('ps1');
    //var dbRefps1 = firebase.database().ref().child('message1');
    //dbRefps1.on('value', snap => ps1.innerText = snap.val());

    //var ps2= document.getElementByID('ps2');
    //var dbRefps2 = firebase.database().ref().child('message2');
    //dbRefps2.on('value', snap => ps2.innerText = snap.val());

    //var ps3= document.getElementByID('ps3');
    //var dbRefps3 = firebase.database().ref().child('message3');
    //dbRefps3.on('value', snap => ps3.innerText = snap.val());
