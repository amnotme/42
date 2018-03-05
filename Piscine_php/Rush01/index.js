$(document).ready(function() {
	var serverqqq = null;
  $(function() {
    $( "#resizable" ).resizable({
      minHeight: 540,
      minWidth: 750,
      animate: true
    });
  });

	$(".creategame").on('submit', function(e){
		e.preventDefault();
		var request = $.ajax({
		  url: "/serverinfo.php",
		  type: "POST",
		  data: $( this ).serializeArray(),
		});

		request.done(function(msg) {
			alert("Update the server list please");
		});

		request.fail(function(jqXHR, textStatus) {
		  alert( "Request failed: " + textStatus );
		});
	});
  $("#refserver").on('click', function() {
	var request = $.ajax({
	  url: "/serverinfo.php",
	  type: "GET",
	  data: {action: "servers"},
	});

	request.done(function(msg) {
		let oserver = [];
		$.each(msg, function(i, item) {
			var server = "<div class='server' id=" + msg[i].id + '>' +
				"Server name: " + msg[i].name +
			"</div>";
			oserver.push(server);
	  	});
		$("#servers").empty().append(oserver);
	});

	request.fail(function(jqXHR, textStatus) {
	  alert( "Request failed: " + textStatus );
	});
  });
	$('#servers').on('click', '.server', function() {
		$("#servbutt").prop("disabled", false);
		serverqqq = $(this).attr('id');
		var request = $.ajax({
		  url: "/serverinfo.php",
		  type: "GET",
		  data: {action: "server", id: $(this).attr('id')},
		});

		request.done(function(msg) {
			serverqqq = msg.servinfo.id;
			var server = "<div class='sinfo' id=" + msg.servinfo.id + '>' +
				"<p>Server name: " + msg.servinfo.name + '</p>' +
				"<p>Server description: " + msg.servinfo.metadata + '</p>' +
				"<p>Max players: " + msg.servinfo.max_number + '</p>' +
			"</div>";
			$("#serinfo").empty().append(server);
			var users = [];
			$.each(msg.users, function(i, item) {
				var user = "<p class='servuser'>" +
					"User: " + msg.users[i].login +
				"</p>";
				users.push(user);
		  	});
			$("#servplayers").empty().append(users);
		});

		request.fail(function(jqXHR, textStatus) {
		  alert( "Request failed: " + textStatus );
		});
	});
	$('#servbutt').on('click', function() {
		$("#servbutt").prop("disabled", true);
		var request = $.ajax({
		  url: "/serverinfo.php",
		  type: "POST",
		  data: {action: "servjoin", id: serverqqq},
		});

		request.done(function(msg) {
			var request = $.ajax({
			  url: "/serverinfo.php",
			  type: "GET",
			  data: {action: "server", id: serverqqq},
			});

			request.done(function(msg) {
				serverqqq = msg.servinfo.id;
				var server = "<div class='sinfo' id=" + msg.servinfo.id + '>' +
					"<p>Server name: " + msg.servinfo.name + '</p>' +
					"<p>Server description: " + msg.servinfo.metadata + '</p>' +
					"<p id='maxplayers'> Max players: <span>" + msg.servinfo.max_number + '</span></p>' +
				"</div>";
				$("#serinfo").empty().append(server);
				var users = [];
				$.each(msg.users, function(i, item) {
					var user = "<p class='servuser'>" +
						"User: " + msg.users[i].login +
					"</p>";
					users.push(user);
				});
				$("#servplayers").empty().append(users);
				console.log(msg.users.length);
				if (msg.users.length == $("#maxplayers span").text())
					$(location).attr('href', './game.php?id='+serverqqq);
			});

			request.fail(function(jqXHR, textStatus) {
			  alert( "Request failed: " + textStatus );
			});
		});

		request.fail(function(jqXHR, textStatus) {
		  alert( "Request failed: " + textStatus );
		});
	});

  $(function() {
    $( "#sortable" ).sortable();
    $( "#sortable" ).disableSelection();
  });
  var bg = 'body .wrap',
  // Games var
      games = 'wow d3 hs sc2 hots ip',
  // Filter var
      gamesblur = 'wowblur d3blur hsblur sc2blur hotsblur ipblur',
  // Game Wrap var
      gamewrap = '.game-wrap .wowcontainer, .hscontainer, .sc2container, .d3container, .hotscontainer, .ipcontainer';
  // Aside and Main Nav Active State
  $('.item').click(function() {
    var $siblings = $(this).parent().children();
    $siblings.removeClass('active');
    $(this).addClass('active');
  });
  $('nav ul li a').click(function() {
    $('nav ul li a').removeClass('active');
    $(this).addClass('active');
  });
  // Main Nac Selection
  var wrap = '.wrap-games, .wrap-shop, .wrap-news';
  $('nav ul li #games').click(function() {
    $(bg).removeClass(games);
    $(bg).addClass('sc2');
    $('.filter').addClass('sc2blur');
    $(wrap).removeClass('active');
    $('.wrap-games').addClass('active');
  });
  $('nav ul li #shop').click(function() {
    $('.filter').removeClass(gamesblur);
    $(bg).removeClass(games);
    $(wrap).removeClass('active');
    $('.wrap-shop').addClass('active');
  });
  $('nav ul li #news').click(function() {
    $('.filter').removeClass(gamesblur);
    $(bg).removeClass(games);
    $(wrap).removeClass('active');
    $('.wrap-news').addClass('active');
  });
  // Games item Click Event (Background change content add)
 $('.item.sc2').click(function() {
   $(bg).removeClass(games);
   $(bg).addClass('sc2');
   $('.filter').removeClass(gamesblur);
   $('.filter').addClass('sc2blur');
   $(gamewrap).removeClass('active');
   $('.game-wrap .sc2container').addClass('active');
   $('video').removeClass('active');
 });

 $('.item.hs').click(function() {
   $(bg).removeClass(games);
   $(bg).addClass('hs');
   $('.filter').removeClass(gamesblur);
   $('.filter').addClass('hsblur');
   $(gamewrap).removeClass('active');
   $('.game-wrap .hscontainer').addClass('active');
   $('video').removeClass('active');
   var request = $.ajax({
	 url: "/serverinfo.php",
	 type: "GET",
	 data: {action: "leaderboard"},
   });

   request.done(function(msg) {
	   let ouslead = [];
	   $.each(msg, function(i, item) {
		   var lead = "<tr>" +
			   "<td>"+ msg[i].login + "</td>" +
			   "<td>"+ msg[i].wins + "</td>" +
			   "<td>"+ msg[i].loses + "</td>" +
		   "</tr>";
		   ouslead.push(lead);
	   });
	   $(".content-wrap table").empty().append(ouslead);
   });

   request.fail(function(jqXHR, textStatus) {
	 alert( "Request failed: " + textStatus );
   });
 });
 $('.item.ip').click(function() {
   $(bg).removeClass(games);
   $(bg).addClass('ip');
   $('.filter').removeClass(gamesblur);
   $('.filter').addClass('ipblur');
   $(gamewrap).removeClass('active');
   $('.game-wrap .ipcontainer').addClass('active');
   $('video').removeClass('active');
   var request = $.ajax({
	  url: "/serverinfo.php",
	  type: "GET",
	  data: {action: "ip"},
   });

   request.done(function(msg) {
	   var ip = "<div class='ipuser'" +
		   "<p>Name: " + msg.login + '</p>' +
		   "<p>Wins: " + msg.wins + '</p>' +
		   "<p>Losses: " + msg.loses + '</p>' +
	   "</div>";
	   $("#ip").empty().append(ip);
   });

   request.fail(function(jqXHR, textStatus) {
  	alert( "Request failed: " + textStatus );
   });
 });
 $('header .logo').hover(function() {
   $('.hover').toggle("slide");
 });
 $('header .logo').click(function() {
   $('aside').toggleClass('slide');
   $('.game-wrap').toggleClass('slide');
 });
});
