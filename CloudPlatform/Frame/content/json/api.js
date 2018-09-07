
/*
 * 
 * Storage
 */
(function(window){
    var u = {};
    var uzStorage = function(){
        var ls = window.localStorage;
        return ls;
    };
    u.setStorage = function(key, value){
        if(arguments.length === 2){
            var v = value;
            if(typeof v == 'object'){
                v = JSON.stringify(v);
                v = 'obj-'+ v;
            }else{
                v = 'str-'+ v;
            }
            var ls = uzStorage();
            if(ls){
                ls.setItem(key, v);
            }
        }
    };
    u.getStorage = function(key){
        var ls = uzStorage();
        if(ls){
            var v = ls.getItem(key);
            if(!v){return;}
            if(v.indexOf('obj-') === 0){
                v = v.slice(4);
                return JSON.parse(v);
            }else if(v.indexOf('str-') === 0){
                return v.slice(4);
            }
        }
    };
    u.rmStorage = function(key){
        var ls = uzStorage();
        if(ls && key){
            ls.removeItem(key);
        }
    };
    u.clearStorage = function(){
        var ls = uzStorage();
        if(ls){
            ls.clear();
        }
    };

/*end*/
    

    window.$api = u;

})(window);


