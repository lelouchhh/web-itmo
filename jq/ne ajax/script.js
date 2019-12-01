$(".links").css("color", "green");
$(".parag").css("color", "green");
$("form *").attr("disabled", "disabled");

$("a").prepend("↗").attr("target", "_blank").attr("href", function(index, value) {
        value = value.split("http");
        if (value[0] == "" && value[1][0] != "s") { 
            value.splice(0, 1);
            return "https" + value.join("http");
        }
        return value.join(`http`);
    });;

function remove(){
    $("a").removeAttr("target").html(function(index, value) {
            if (value[0] == "↗") {
                return value.slice(1);
            }
            return value;
        });
};
$(`.button_toggle`).click(function() {
    $("#one").toggle(100);
});
$(".button_fadeToggle").click(function() {
    $("#two").fadeToggle(500);
});
$(".button_slideToggle").click(function() {
    $("#four").slideToggle(1000);
});
$(".button_animate").click(function() {
    console.log(4);

    $("#five").animate({ fontSize: "2em" });
});
$(".button_hide").click(function() {
    $("#six").hide(1000);
});