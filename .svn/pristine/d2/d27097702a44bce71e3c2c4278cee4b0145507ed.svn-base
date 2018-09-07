(function (w) {
    var main = {};

    var alerttag=false;

    main.Initialize = function () {
        var tmp = $('#func-frame').offset();
        var h = $(document).height() - tmp.top - 15;
        $('.frame-box').css('height', h + 'px');
    };
    main.onFunc = function (id) {
        var yes = false;
        var clsn = $('#' + id +' a').prop('class');
        if (clsn.indexOf('disabled') > -1) {
            return yes;
        }
        var url = $('#' + id).attr('data-func');
        if (!$api.isNull(url)) {
            url = url + '?v=' + $api.getUUID(16);
        }
        $('#func-frame').prop('src', url);
        $('#func-menu li').removeClass('active');
        $('#' + id).parents('li').addClass('active');
        $('#' + id).addClass('active');
        yes = true;
        return yes;
    };
    main.onMenu = function (id) {
        var yes = false;
        var clsn = $('#' + id).prop('class');
        if (clsn.indexOf('disabled') > -1) {
            return yes;
        }
        $('#content-menu li').removeClass('active');
        $('#' + id).addClass('active');
        yes = true;
        return yes;
    };

    main.openLoading = function (title, text) {
        $('#loading-modal-title').text(title);
        $('#loading-modal-body').text(text);
        $('#input-loading').modal({
            backdrop: 'static',
            keyboard: false
        });
    };
    main.closeLoading = function () {
        $('#input-loading').modal('hide');
    };
    main.openAlert = function (title, text, callback) {
        $('#alert-dialog').modal('hide');
        $('#alert-dialog-modal-title').text(title);
        $('#alert-dialog-modal-body').text(text);
        if ($api.isNull(callback)) {
            $('#modal-dialog-close').hide();
        } else {
            $('#modal-dialog-close').show();
            $('#alert-dialog').on('hidden.bs.modal', function (e) {
                callback(alerttag);
                $('#alert-dialog').unbind('hidden.bs.modal');
            });
        }

        $('#alert-dialog').modal('show');
    };
    main.closeAlert = function (tag) {
        alerttag = tag;
        $('#alert-dialog').modal('hide');
    };

    w.ui_main = main;
})(window);