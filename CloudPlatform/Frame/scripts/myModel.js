

$(document).ready(function() {
	$('.myModal').on('show.bs.modal', centerModals);
	$(".myModal").draggable();//可拖拽
	//禁用空白处点击关闭
	$('.myModal').modal({
	backdrop: 'static',
	keyboard: false,//禁止键盘
	show:false
	});
	//页面大小变化是仍然保证模态框水平垂直居中
	$(window).on('resize', centerModals);
});
function centerModals() {   
	　　$('.myModal').each(function(i) {   
	　　　　var $clone = $(this).clone().css('display','block').appendTo('body');
	　　　　var top = Math.round(($clone.height() - $clone.find('.modal-content').height()) / 2);
	　　　　top = top > 0 ? top : 0;   
	　　　　$clone.remove();   
	　　　　$(this).find('.modal-content').css("margin-top", top);   
	　　});   
	};  
	
	
