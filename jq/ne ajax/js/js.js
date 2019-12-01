$(document).ready(function(){

	$( ".button1" ).click(function() {
		$(".links").css("fontSize","20px");
		$(".links").css("margin-left","18px");
		$(".links").css("text-align","center");
		$(".links").css("display","inline");

		$(".button1").css("margin-left","15px");
		$(".button1").css("margin-top","15px");

		$(".post-1").css("margin-bottom","20px");

		$(".first").css("text-align","center");
		$(".first").css("fontSize","20px");
		$(".first").css("color","red");		

});
	 
	 $( ".button2" ).click(function() {
	 	$(".button2").css("display","none");

	 	$(".links").css("fontSize","15px");
	 	$(".links").prepend("↗");
		
});
	 $(".post-2").hover(function() {
 	 $(this).stop().animate({ backgroundColor: "#FF4500"}, 400);
 	 },function() {
 	 $(this).stop().animate({ backgroundColor: "#87cefa" }, 400);

 });
	  $( ".out" ).click(function(){ // задаем функцию при нажатиии на элемент с классом out
	    $( ".post-3" ).fadeOut(); // плавно изменяя прозрачность скрываем все элементы <div>
	  });
	  $( ".in" ).click(function(){ // задаем функцию при нажатиии на элемент с классом in
	    $( ".post-3" ).fadeIn(); // плавно изменяя прозрачность отображаем все элементы <div>
	  });
	  
	  $( document ).ready(function(){
	  $( ".all1" ).click(function(){ // задаем функцию при нажатиии на элемент с классом out
	    $( ".post-4" ).fadeOut( "slow" ); // плавно изменяя прозрачность скрывааем первый элемент <div> в документе
	    $( ".post-3" ).fadeOut( 1000 ); // плавно изменяя прозрачность скрывааем второй элемент <div> в документе
	    $( ".post-1" ).fadeOut( "fast" ); // плавно изменяя прозрачность скрывааем последний элемент <div> в документе
	  });
	  $( ".all2" ).click(function(){ // задаем функцию при нажатиии на элемент с классом in
	    $( ".post-1" ).fadeIn( "slow" ); // плавно изменяя прозрачность отображаем первый элемент <div> в документе
	    $( ".post-3" ).fadeIn( 1000 ); // плавно изменяя прозрачность отображаем второй элемент <div> в документе
	    $( ".post-4" ).fadeIn( "fast" ); // плавно изменяя прозрачность отображаем последний элемент <div> в документе
	  });
	});
});

