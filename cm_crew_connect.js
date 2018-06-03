(function ($) {
  Drupal.behaviors.crewConnectPositions = {
    attach: function (context, settings) {
      ////////////////////////////////////////////////////////////////////////
      //ON READY FUNCTION
      $(document).ready(function() {
	var should_filter =
	    $('input[name=crew_connect_filter_positions]').val();

	if (should_filter == 'yes') {
	  cmCrewConnectConditionalSelects();
	}
      });
      ////////////////////////////////////////////////////////////////////////
      //CHANGE FUNCTION FOR VOLUNTEER TYPE FIELD
      $("select[id$='edit-field-crew-opportunity-type-und']", context).
	change(function() {
	  var should_filter =
	      $('input[name=crew_connect_filter_positions]').val();

	  if (should_filter == 'yes') {
	    cmCrewConnectConditionalSelects();
	  }
	});

      ////////////////////////////////////////////////////////////////////////
      //FUNCTION WILL HANDLE INTERACTIONS BETWEEN POSITION AND OPPORTUNITY TYPE
      function cmCrewConnectConditionalSelects() {
	var $pos_select = $('#edit-field-crew-position-taxonomy-und');
	var opp_type =  $('#edit-field-crew-opportunity-type-und').val();
	var position =  $('#edit-field-crew-position-taxonomy-und').val();

	console.log('OPP TYPE: ' + opp_type);
	console.log('POSITION: ' + position);

	if (opp_type == '_none') {
	  $('#edit-field-crew-position-taxonomy').hide();
	}
	else {
	  var cm_url = '/admin/crew_connect/positions?opp_type=' + opp_type;
	  console.log(cm_url);
	  //REMOVE CURRENT OPTIONS, REPLACE WITH OPTIONS FROM AJAX CALL
	  $pos_select.empty();
	  if (position == '_none') {
	    $pos_select.append($("<option></option>")
			     .attr("value", '_none')
			       .attr('selected', true)
			       .text('- Select a value -'));
	    
	  }

	  $.getJSON(cm_url, function(data){
	    if (position && position != '_none') {
	      var invalid_position = 1;
	      $.each(data, function(i,item){
		if (item.id==position) {
		  invalid_position = 0;
		}
	      });
	      console.log('invalid position: ' + invalid_position);
	      if (invalid_position) {
		$pos_select.append($("<option></option>")
				   .attr("value", '_none')
				   .attr('selected', true)
				   .text('- Select a value -'));
		
 	      }
	    }
	    $.each(data, function(i,item){
	      if (item.id==position) {
		$pos_select.append($("<option></option>")
				   .attr("value", item.id)
				   .attr('selected', true)
				   .text(item.label));
	      }
	      else {
		$pos_select.append($("<option></option>")
				   .attr("value", item.id)
				   .text(item.label));
	      }
	      
	    });
	  });

	  $('#edit-field-crew-position-taxonomy').show();	  
	}
      }
    }};
}) (jQuery);

