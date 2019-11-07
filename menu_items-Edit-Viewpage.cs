@model dynamic
@using NutriTrust
@using NutriTrust.Models

@{
    menu_items menu_item = Model.menuItem;
    List<menu_items> menu_Items = Model.menu_Items;

    item_nutrition item_Nutrition = Model.itemNutrition;
    List<category> categories = Model.categories;
    List<category> categoryOptions = Model.categoryOptions;

    List<custom_filters> customFilters = Model.customFilters;
    List<custom_filters> customFilterOptions = Model.customFilterOptions;

    List<default_filters> defaultFilters = Model.defaultFilters;
    List<default_filters> defaultFilterOptions = Model.defaultFilterOptions;

    List<default_filters> glutentFilters = Model.glutentFilters;
    List<default_filters> glutenFilterOptions = Model.glutenFilterOptions;

    List<default_filters> allergenFilters = Model.allergenFilters;
    List<default_filters> allergenFilterOptions = Model.allergenFilterOptions;

    List<J_menu_items_default_filters> J_menu_items_default_filters = Model.J_menu_items_default_filters;

    item_avail item_Avails = Model.item_Avails;

    List<menu_items_igroup> menuItemIgroup = Model.menuItemIgroup;

    int?[] childItemsSelected = Model.childItemsSelected;

    int?[] alternateVersionsSelected = Model.alternateVersionsSelected;

    Dictionary<string, Dictionary<int, int[]>> VariableDictionary = Model.VariableDictionary;
}

<div class="row wrapper border-bottom white-bg page-heading">
    <div class="col-sm-4">
        <h2>Edit</h2>
        <ol class="breadcrumb">
            <li>
                @Html.ActionLink("List", "Index")
            </li>
            <li class="active">
                <strong>Edit</strong>
            </li>
        </ol>
    </div>

    <div class="col-sm-8">
        <div class="title-action">
            @Html.ActionLink("Back to List", "Index", null, new { @class = "btn btn-primary" })
        </div>
    </div>
</div>

<div class="wrapper wrapper-content animated fadeInRight ibox-content">
    <div class="row">
        <div class="col-lg-12">
            <div class="ibox float-e-margins">
                <div class="ibox-title">
                    <h5>Edit menu_items</h5>
                </div>
                <div class="ibox-content">

                    @using (Html.BeginForm())
                    {
                        @Html.AntiForgeryToken()
                        @Html.Hidden("menu_item_id", menu_item.id)
                        @Html.Hidden("client_id", menu_item.client_id)
                        @Html.Hidden("created_date", menu_item.created_date)
                        @Html.Hidden("modification_date", menu_item.modification_date)
                        @Html.Hidden("deleted", menu_item.deleted)
                        @Html.Hidden("pending", menu_item.pending)

                        <div class="col-sm-6 editMenuItem editMenuItemLeft">
                            <p>@Html.Label("Name")                 @Html.EditorFor(Model => menu_item.name, new { htmlAttributes = new { Name = "name", @class = "menu_item" } })</p>
                            @Html.CheckBox("as_ingredient", (bool)menu_item.as_ingredient, new { @class = "form-control" })@Html.Label("As Ingredient")
                            <br />
                            @Html.Label("Child Alias")             @Html.EditorFor(Model => menu_item.child_alias, new { htmlAttributes = new { Name = "child_alias", @class = "menu_item" } })
                            @Html.Label("Ingredient Alias")        @Html.EditorFor(Model => menu_item.ingred_alias, new { htmlAttributes = new { Name = "ingred_alias", @class = "menu_item" } })
                            @Html.Label("Version Alias")           @Html.EditorFor(Model => menu_item.version_alias, new { htmlAttributes = new { Name = "version_alias", @class = "menu_item" } })
                            @Html.Label("Nutrition Chart Alias")   @Html.EditorFor(Model => menu_item.nutrition_alias, new { htmlAttributes = new { Name = "nutrition_alias", @class = "menu_item" } })
                            <br />
                            @Html.CheckBox("hide_on_NC", (bool)menu_item.hide_on_NC, new { @class = "form-control" }) @Html.Label("Hide on Nutrition Chart")
                            <br />
                            @Html.CheckBox("hide_on_MP", (bool)menu_item.hide_on_MP, new { @class = "form-control" }) @Html.Label("Hide on Menu Page")
                            <br />
                            @Html.CheckBox("mb", (bool)menu_item.mb, new { @class = "form-control" }) @Html.Label("Menu Builder")
                            <br />
                            @Html.CheckBox("quanto", (bool)menu_item.quanto) @Html.Label("Use Quantities")

                            @Html.Label("Quantities Multiplier")   @Html.EditorFor(Model => menu_item.quanto_multiplier, new { htmlAttributes = new { Name = "quanto_multiplier", @class = "menu_item" } })
                            @Html.Label("Custom ID")               @Html.EditorFor(Model => menu_item.cmiid, new { htmlAttributes = new { Name = "cmiid", @class = "menu_item" } })
                            @Html.CheckBox("use_cmiid", (bool)menu_item.use_cmiid) @Html.Label("As Shell")
                            @Html.Label("Description")             @Html.TextAreaFor(Model => menu_item.description, new { Name = "description", @class = "menu_item" })
                            @Html.Label("Short Description")       @Html.TextAreaFor(Model => menu_item.s_descriptions, new { Name = "s_descriptions", @class = "menu_item" })
                            @Html.Label("Meta-Data")               @Html.EditorFor(Model => menu_item.meta, new { htmlAttributes = new { Name = "meta", @class = "menu_item" } })
                            @Html.Label("Notes")                   @Html.TextAreaFor(Model => menu_item.notes, new { Name = "notes", @class = "menu_item" })
                            @Html.Label("Ingredient Declaration")  @Html.TextAreaFor(Model => menu_item.ingredient_dec, new { Name = "ingredient_dec", @class = "menu_item" })
                            @Html.Label("Special Request")         @Html.TextAreaFor(Model => menu_item.special_req, new { Name = "special_req", @class = "menu_item" })
                            @Html.Partial("_Images", null, new ViewDataDictionary { { "FieldName", "menu_item_image" } })
                            @Html.Label("Default Price")           @Html.EditorFor(Model => menu_item.price, new { htmlAttributes = new { Name = "price", @class = "menu_item" } })

                            @Html.Label("Categories")
                            @Html.DropDownListFor(Model => categories, new MultiSelectList(categoryOptions, "id", "name", categories.Select(x => x.id).ToArray()), new { Name = "categories", multiple = "multiple", @class = "form-control categories chosen-select" })
                            @Html.Label("Available Options Nomenclature") @Html.EditorFor(Model => menu_item.avail_opt, new { htmlAttributes = new { Name = "avail_opt", @class = "menu_item" } })
                        </div>

                        <style>
                            .itemNutritionStyling {
                                width: 50px;
                                float: right;
                            }
                        </style>

                        @Html.Hidden("itemNutritionID", item_Nutrition.id)
                        @Html.Hidden("itemNutritionCreated", item_Nutrition.created)
                        @Html.Hidden("itemNutritionCreatedBy", item_Nutrition.createdby)


                        <div class="col-sm-6 editMenuItem editMenuItemRight">
                            <p>@Html.Label("Quantity")  @Html.EditorFor(Model => item_Nutrition.q, new { htmlAttributes = new { Name = "q", @class = "itemNutritionStyling" } })</p>
                            <hr />
                            <p>@Html.Label("Unit of Measurement") @Html.EditorFor(Model => item_Nutrition.aum, new { htmlAttributes = new { Name = "aum", @class = "itemNutritionStyling" } })</p>
                            <hr />
                            <p>
                                @Html.Label("Calories") @Html.EditorFor(Model => item_Nutrition.calories, new { htmlAttributes = new { Name = "calories", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /> <p>
                                @Html.Label("Calories from fat")  @Html.EditorFor(Model => item_Nutrition.calories_from_fat, new { htmlAttributes = new { Name = "calories_from_fat", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Fat")   @Html.EditorFor(Model => item_Nutrition.fat, new { htmlAttributes = new { Name = "fat", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Saturated Fat")    @Html.EditorFor(Model => item_Nutrition.sat_fat, new { htmlAttributes = new { Name = "sat_fat", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Trans Fat")   @Html.EditorFor(Model => item_Nutrition.trans_fat, new { htmlAttributes = new { Name = "trans_fat", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Cholesterol")   @Html.EditorFor(Model => item_Nutrition.cholest, new { htmlAttributes = new { Name = "cholest", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Sodium")   @Html.EditorFor(Model => item_Nutrition.sodium, new { htmlAttributes = new { Name = "sodium", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Carbs")    @Html.EditorFor(Model => item_Nutrition.carbs, new { htmlAttributes = new { Name = "carbs", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Fiber")   @Html.EditorFor(Model => item_Nutrition.fiber, new { htmlAttributes = new { Name = "fiber", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Sugar")   @Html.EditorFor(Model => item_Nutrition.sugar, new { htmlAttributes = new { Name = "sugar", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Protien")  @Html.EditorFor(Model => item_Nutrition.protein, new { htmlAttributes = new { Name = "protein", @class = "itemNutritionStyling" } })
                            </p>
                            <hr /><p>
                                @Html.Label("Fruits & Veggies")  @Html.EditorFor(Model => item_Nutrition.fruit_veg, new { htmlAttributes = new { Name = "fruit_veg", @class = "itemNutritionStyling" } })
                            </p>
                            <hr />


                            @Html.Label("Filters")
                            @Html.DropDownListFor(Model => defaultFilters, new MultiSelectList(defaultFilterOptions, "id", "filter_name", defaultFilters.Select(x => x.id).ToArray()), new { Name = "defaultFilters", multiple = "multiple", @class = "form-control defaultFilters chosen-select" })

                            @Html.Label("Custom Filters")
                            @Html.DropDownListFor(Model => customFilters, new MultiSelectList(customFilterOptions, "id", "name", customFilters.Select(x => x.id).ToArray()), new { Name = "customFilters", multiple = "multiple", @class = "form-control customFilters chosen-select" })

                            @Html.Label("Gluten")
                            @Html.DropDownListFor(Model => glutentFilters, new MultiSelectList(glutenFilterOptions, "id", "filter_name", glutentFilters.Select(x => x.id).ToArray()), new { Name = "glutenFilters", multiple = "multiple", @class = "form-control glutenFilters chosen-select" })

                            @Html.Label("Allergens")
                            @{
                                List<int> allergenIdsArray = new List<int> { 15, 18, 19, 20, 39, 41, 46, 49 };
                                List<default_filters> allergenFilterOptionsModified = allergenFilterOptions.Where(x => !allergenIdsArray.Contains(x.id)).ToList();
                                List<default_filters> allergenFilterOptionsWithTypes = allergenFilterOptions.Where(x => allergenIdsArray.Contains(x.id)).ToList();
                                foreach (var x in allergenFilterOptionsModified)
                                {
                                    x.filter_name = x.filter_name.Replace("Made without", "");
                                }
                                @Html.DropDownListFor(Model => allergenFilters, new MultiSelectList(allergenFilterOptionsModified, "id", "filter_name", allergenFilters.Select(x => x.id).ToArray()), new { Name = "allergenFilters", multiple = "multiple", @class = "form-control allergenFilters chosen-select" })
                            }


                            @*Fish*@
                            <div class="row">
                                <div class="col-sm-3">
                                    @Html.Label("Fish")
                                    @{
                                        if (ViewBag.WoutFish)
                                        {
                                            @Html.CheckBox("WoutFish", true, new { @class = "form-control" })

                                        }
                                        else
                                        {
                                            @Html.CheckBox("WoutFish", false, new { @class = "form-control" })
                                        }
                                    }
                                </div>
                                <div class="col-sm-3">
                                    @Html.Label("Cross Contact")
                                    @{
                                        if (ViewBag.fishCC)
                                        {
                                            @Html.CheckBox("fishCC", true, new { @class = "form-control" })
                                        }
                                        else
                                        {
                                            @Html.CheckBox("fishCC", false, new { @class = "form-control" })
                                        }
                                    }
                                </div>

                                <div class="col-sm-6">
                                    @Html.Label("Type of Fish")
                                    <br />
                                    @{
                                        if (ViewBag.Fish != null)
                                        {
                                            @Html.TextBox("fishType", (string)ViewBag.Fish, new { Name = "fishType" })
                                        }
                                        else
                                        {
                                            @Html.TextBox("fishType", null, new { Name = "fishType" })
                                        }
                                    }
                                </div>
                            </div>

                            @*Shellfish*@
                            <div class="row">
                                <div class="col-sm-3">
                                    @Html.Label("Shellfish")
                                    @{
                                        if (ViewBag.WoutShellfish)
                                        {
                                            @Html.CheckBox("WoutShellfish", true, new { @class = "form-control" })
                                        }
                                        else
                                        {
                                            @Html.CheckBox("WoutShellfish", false, new { @class = "form-control" })
                                        }
                                    }
                                </div>
                                <div class="col-sm-3">
                                    @Html.Label("Cross Contact")
                                    @{
                                        if (ViewBag.shellfishCC)
                                        {
                                            @Html.CheckBox("shellfishCC", true, new { @class = "form-control" })
                                        }
                                        else
                                        {
                                            @Html.CheckBox("shellfishCC", false, new { @class = "form-control" })
                                        }
                                    }
                                </div>
                                <div class="col-sm-6">
                                    @Html.Label("Type of Shellfish")


                                    @{
                                        if (ViewBag.ShellFish != null)
                                        {
                                            @Html.TextBox("shellfishType", (string)ViewBag.ShellFish, new { Name = "shellfishType" })
                                        }
                                        else
                                        {
                                            @Html.TextBox("shellfishType", null, new { Name = "shellfishType" })
                                        }
                                    }
                                </div>
                            </div>

                            @*Mollusk*@
                            <div class="row">
                                <div class="col-sm-3">
                                    @Html.Label("Mollusks")
                                    @{
                                        if (ViewBag.WoutMollusks)
                                        {
                                            @Html.CheckBox("WoutMollusks", true, new { @class = "form-control" })
                                        }
                                        else
                                        {
                                            @Html.CheckBox("WoutMollusks", false, new { @class = "form-control" })
                                        }
                                    }
                                </div>
                                <div class="col-sm-3">
                                    @Html.Label("Cross Contact")
                                    @{
                                        if (ViewBag.mollusksCC)
                                        {
                                            @Html.CheckBox("mollusksCC", true, new { @class = "form-control" }) }
                                        else
                                        { @Html.CheckBox("mollusksCC", new { @class = "form-control" })}
                                    }
                                </div>
                                <div class="col-sm-6">
                                    @Html.Label("Type of Mollusks")
                                    @{
                                        if (ViewBag.Mollusk != null)
                                        {
                                            @Html.TextBox("mollusksType", (string)ViewBag.Mollusk, new { Name = "mollusksType" })
                                        }
                                        else
                                        {
                                            @Html.TextBox("mollusksType", null, new { Name = "mollusksType" })
                                        }
                                    }

                                </div>
                            </div>

                            @*Tree Nuts*@
                            <div class="row">
                                <div class="col-sm-3">
                                    @Html.Label("Tree Nuts")
                                    @{
                                        if (ViewBag.WoutTreenuts)
                                        {
                                            @Html.CheckBox("WoutTreenuts", true, new { @class = "form-control" })
                                        }
                                        else
                                        {
                                            @Html.CheckBox("WoutTreenuts", new { @class = "form-control" })
                                        }
                                    }
                                </div>
                                <div class="col-sm-3">
                                    @Html.Label("Cross Contact")
                                    @{
                                        if (ViewBag.treeNutsCC)
                                        {
                                            @Html.CheckBox("treeNutsCC", true, new { @class = "form-control" })}
                                        else
                                        {
                                            @Html.CheckBox("treeNutsCC", new { @class = "form-control" })
                                        }
                                    }


                                </div>
                                <div class="col-sm-6">
                                    @Html.Label("Type of Tree nuts")


                                    @{
                                        if (ViewBag.Tree != null)
                                        {
                                            @Html.TextBox("treeType", (string)ViewBag.Tree, new { Name = "treeType" })
                                        }
                                        else
                                        {
                                            @Html.TextBox("treeType", null, new { Name = "treeType" })
                                        }
                                    }

                                </div>
                            </div>

                            @Html.Label("Alternate Versions Group Name")
                            <br />
                            @Html.TextBox("altv_group_name", menu_item.altv_group_name)

                            <br />
                            @Html.Label("Alternate Versions")  @Html.DropDownListFor(Model => menu_Items, new MultiSelectList(menu_Items, "id", "name", alternateVersionsSelected), new { Name = "AlternateVersionsDropdown", multiple = "multiple", @class = "form-control menuItems chosen-select" })
                            <br />
                            @Html.Label("Child Group Name") <br />@Html.TextBox("child_group_name", menu_item.child_group_name)
                            <br />
                            @Html.Label("Child Items") @Html.DropDownListFor(Model => menu_Items, new MultiSelectList(menu_Items, "id", "name", childItemsSelected), new { Name = "child_Items", multiple = "multiple", @class = "form-control menuItems chosen-select" })


                            @* item_avail *@
                            @Html.Hidden("IA_created", item_Avails.created)
                            @Html.Hidden("IA_createdby", item_Avails.createdby)
                            @Html.Hidden("IA_deleted", item_Avails.deleted)
                            @Html.Hidden("itemAvailID", item_Avails.id)
                            @Html.Hidden("IA_menu_item_id", item_Avails.menu_item_id)


                            <br /><br /><br />
                        </div>
                        @* Variable Ingredients *@
                        <div style="background-color:aliceblue" class="col-sm-12">Variable Ingredients<button class="btn btn-primary" style="float:right" type="button" data-toggle="collapse" data-target="#variableIngredientsExpandDiv"><i class="fa fa-arrow-down"></i></button></div>
                        <div class="col-sm-12 collapse" id="variableIngredientsExpandDiv">
                            <button style="float:right" type="button" class="btn btn-primary" data-toggle="modal" data-target="#createVIngredientModal">Add Group</button>

                            @*variable ingredient MODAL*@
                            <div id="createVIngredientModal" class="modal fade" role="dialog">
                                <div class="modal-dialog">

                                    <!-- Modal content-->
                                    <div class="modal-content">
                                        <div class="modal-header">
                                            <button type="button" class="close" data-dismiss="modal">&times;</button>
                                            <h4 class="modal-title">Create Variable Ingredient</h4>
                                        </div>
                                        <div class="modal-body">

                                            @Html.Label("Sort Order")@Html.TextBox("group_sortAjax", null, new { Type = "number" })
                                            <br />
                                            @Html.Label("Ingredient Name")@Html.TextBox("VnameAjax")
                                            <br />
                                            @Html.Label("Display name")@Html.CheckBox("display_nameAjax", false)
                                            <br />
                                            @Html.Label("Radio")@Html.CheckBox("radioAjax", false, new { @value = false })
                                            <br />
                                            @Html.Label("Default Label")@Html.TextBox("defaultAjax")
                                            <br />
                                            @Html.Label("Show on Menu")@Html.CheckBox("showon_menuAjax", false, new { @value = false })
                                            <br />
                                            @Html.Label("Show on Landing")@Html.CheckBox("showon_landingAjax", false, new { @value = false })
                                            @Html.Hidden("menuItemId", menu_item.id)


                                        </div>
                                        <div class="modal-footer">
                                            <button type="button" class="btn btn-primary" id="VIngredientAjax">Save</button>
                                            <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
                                        </div>
                                    </div>

                                </div>
                            </div>
                            @*AJAX CALL CODE FOR MODAL*@
                            <script type="text/javascript">
                                $(function () {

                                    //alert(dispChecked)
                                    $("#VIngredientAjax").click(function () {
                                        if ($('#group_sortAjax').val() == "") {
                                            alert("sorting number required")
                                        } else {
                                            var dispChecked = Boolean($('#display_nameAjax').is(':checked'));
                                            var radio = Boolean($('#radioAjax').is(':checked'));
                                            var showon_menu = Boolean($('#showon_menuAjax').is(':checked'));
                                            var showon_landing = Boolean($('#showon_landingAjax').is(':checked'));
                                            $.ajax({
                                                url: '/menu_items/PostVariableIngredients',
                                                type: 'POST',
                                                data: JSON.stringify({
                                                    group_sort: $('#group_sortAjax').val(),
                                                    pub: true,
                                                    menu_item_id: $('#menuItemId').val(),
                                                    name: $('#VnameAjax').val(),
                                                    display_name: dispChecked,
                                                    radio: radio,
                                                    showon_menu: showon_menu,
                                                    showon_landing: showon_landing,
                                                    default: $('#defaultAjax').val()
                                                }),
                                                contentType: 'application/json; charset=utf-8',
                                                success: function () {

                                                },
                                                error: function () {
                                                    alert("error");
                                                }
                                            });
                                        }
                                    });
                                });

                            </script>


                            @*END variable ingredient MODAL*@

                            <table class="table-striped table dataTables">
                                <thead>
                                    <tr>
                                        <th style="width:5%">
                                            Pub
                                        </th>
                                        <th style="width:90%">
                                            Name
                                        </th>
                                        <th style="width:5%">
                                            Customize
                                        </th>
                                    </tr>
                                </thead>
                                <tbody>

                                    @foreach (menu_items_igroup item in menuItemIgroup.OrderBy(x => x.group_sort))
                                    {
                                        <tr>
                                            <td>
                                                @Html.TextBox("group_sort" + item.id, item.group_sort, new { @type = "number", @style = "width:50px" })
                                                @Html.CheckBox("VCheckbox" + item.id, (bool)item.pub)
                                            </td>
                                            <td>
                                                @Html.TextBox("Vname" + item.id, item.name)
                                                <div class="collapse" id="VariableTableData_@item.id">

                                                    <div class="col-sm-6">
                                                        @Html.CheckBox("display_name" + item.id, (bool)item.display_name, new { @class = "form-control" })@Html.Label("Display name")<br />
                                                        <button id="iGroupButton_@item.id" value="@item.id" type="button" class="btn btn-primary" onclick="copyIgroup(@item.id)">Duplicate variable ingredient group to:</button>
                                                        @Html.DropDownListFor(Model => menu_Items, new MultiSelectList(menu_Items, "id", "name", null), new { id = "duplicateGroupTo" + item.id, @class = "form-control menuItems chosen-select" })
                                                        <br />
                                                        @Html.CheckBox("showon_menu" + item.id, (bool)item.showon_menu, new { @class = "form-control" })@Html.Label("Show on Menu")
                                                    </div>
                                                    <div class="col-sm-6">
                                                        @Html.CheckBox("radio" + item.id, (bool)item.radio, new { @class = "form-control" })@Html.Label("Radio")
                                                        <br />
                                                        @Html.Label("Default Label")@Html.TextBox("default" + item.id, item.@default)
                                                        <br />

                                                        @Html.CheckBox("showon_landing" + item.id, (bool)item.showon_landing, new { @class = "form-control" })@Html.Label("Show on Landing")
                                                        <br />
                                                    </div>
                                                    
                                                   
                                                    
                                                    @*<div class="col-sm-12" id="notificationAreaVingredients"></div>*@

                                                    @*<div class="col-sm-12" id="filterDisplayOrder_@item.id">
                                                        <h3>Filter Display & Order</h3>
                                                        @*dual listbox*@
                                                        <div class="form-group col-sm-12">
                                                            @*<select style="display: none;" multiple="multiple" id="dualListbox_@item.id">

                                                                @foreach (var menuItem in menu_Items)
                                                                {
                                                                    <option value="@menuItem.id">@menuItem.name</option>
                                                                }*@
                                                                @*@{
                    string iGroup = Convert.ToString(item.id);
                    Dictionary<int, int[]> currentDictionary = VariableDictionary[iGroup];
                    //Dictionary<int, int[]> sortedDictionary = (Dictionary<int, int[]>)currentDictionary.OrderBy(x => x.Value[1]);
                    var sortedDictionary = from entry in currentDictionary orderby entry.Value[1] ascending select entry;
                    foreach (KeyValuePair<int, int[]> entry in sortedDictionary)
                    {
                        int id = entry.Key;
                        int menuItemID = entry.Value[0];
                        int sortOrder = entry.Value[1];

                string selectedname = menu_Items.Where(x => x.id == menuItemID).Select(x => x.name).First().ToString();
                        <option selected="selected" value="@menuItemID">@selectedname</option>
                    }
                }*@





                                                            @*</select>
                                                        </div>*@


                                                        <div class="sortablearea">
                                                            <div class="col-sm-6" style="height:200px; overflow:scroll">
                                                                <ul id="sortable1" class="connectedSortable">
                                                                    @{
                                                                        foreach (var menuItem in menu_Items)
                                                                        {
                                                                            <li class="ui-state-default" value="@menuItem.id">
                                                                                <input type="checkbox">@menuItem.name
                                                                            </li>
                                                                        }
                                                                    }
                                                                </ul>
                                                            </div>

                                                            <div class="col-sm-6" style="height:200px; overflow:scroll">
                                                                <ul id="sortable2" class="connectedSortable">
                                                                    @{
                                                                        string iGroup = Convert.ToString(item.id);
                                                                        Dictionary<int, int[]> currentDictionary = VariableDictionary[iGroup];
                                                                        var sortedDictionary = from entry in currentDictionary orderby entry.Value[1] ascending select entry;
                                                                        foreach (KeyValuePair<int, int[]> entry in sortedDictionary)
                                                                        {
                                                                            int id = entry.Key;
                                                                            int menuItemID = entry.Value[0];
                                                                            int sortOrder = entry.Value[1];
                                                                            string selectedname = menu_Items.Where(x => x.id == menuItemID).Select(x => x.name).First().ToString();
                                                                            <li class="ui-state-default" value="@menuItemID">
                                                                             <input type="checkbox">@selectedname
                                                                            </li>
                                                                        }
                                                                    }
                                                                </ul>
                                                            </div>
                                                        </div>

                                                        <script>
                                                            $(document).ready(function () {
                                                                //apply dual listbox functionality to the filter display and order listbox
                                                                //$("#dualListbox_@item.id").bootstrapDualListbox({});

                                                                //set width of filter display and order boxes
                                                                //leftSide = $('[name="_helper1"]');
                                                                //rightSide = $('[name="_helper2"]');
                                                                //leftSide.width("400px");
                                                                //rightSide.width("400px");

                                                                //sortable js
                                                                $(function () {
                                                                    $("#sortable1, #sortable2").sortable({
                                                                        connectWith: ".connectedSortable"
                                                                    }).disableSelection();
                                                                });

                                                            });
                                                        </script>

                                                        @*end dual listbox*@
                                                    </div>

                                                    




                                                    @*<div class="variableIngrediends">*@
                                                        @*@{
                string iGroup = Convert.ToString(item.id);
                Dictionary<int, int[]> currentDictionary = VariableDictionary[iGroup];
                foreach (KeyValuePair<int, int[]> entry in currentDictionary)
                {
                    int id = entry.Key;
                    int menu = entry.Value[0];
                    int sortOrder = entry.Value[1];
                    @Html.TextBox(menu.ToString(),menu)
                }
            }*@
                                                    @*</div>*@
                                                </div>
                                            </td>
                                            <td>
                                                <button data-toggle="collapse" data-target="#VariableTableData_@item.id" type="button" class="btn btn-primary"><i class="fa fa-cog"></i></button>
                                            </td>
                                        </tr>
                                    }
                                </tbody>
                            </table>
                            @*Ajax call for duplicating Ingredient group*@
                            <script>
                                function copyIgroup(itemGroup) {

                                    $.ajax({
                                        url: '/menu_items/DuplicateIgroup',
                                        type: 'POST',
                                        data: JSON.stringify({
                                            item_id: $('#duplicateGroupTo' + itemGroup).val(),
                                            group_sort: $('#group_sort' + itemGroup).val(),
                                            VCheckbox: $('#VCheckbox' + itemGroup).is(':checked'),
                                            name: $('#Vname' + itemGroup).val(),
                                            display_name: $('#display_name' + itemGroup).is(':checked'),
                                            radio: $('#radio' + itemGroup).is(':checked'),
                                            default: $('#default' + itemGroup).val(),
                                            showon_menu: $('#showon_menu' + itemGroup).is(':checked'),
                                            showon_landing: $('#showon_landing' + itemGroup).is(':checked'),

                                        }),
                                        contentType: 'application/json; charset=utf-8',
                                        success: function () {
                                            $('#notificationAreaVingredients').html("Success, duplicated group to: " + name);
                                            $('#notificationAreaVingredients').addClass("alert-success");
                                            $('#notificationAreaVingredients').removeClass("alert-danger");
                                        },
                                        error: function () {
                                            $('#notificationAreaVingredients').html("Failure");
                                            $('#notificationAreaVingredients').addClass("alert-danger");
                                            $('#notificationAreaVingredients').removeClass("alert-success");
                                        }
                                    });

                                }
                            </script>
                            @*END AJAX CALL CODE*@
                        </div>



                        @* Special availability settings *@
                        <div style="background-color:aliceblue" class="col-sm-12">Special Availability Settings<br />(e.g., Only available on Mondays between 10am and 2pm)<button class="btn btn-primary" style="float:right" type="button" data-toggle="collapse" data-target="#specialavail"><i class="fa fa-arrow-down"></i></button></div>
                        <div class="col-sm-12 collapse" id="specialavail">
                            <table class="table table-striped dataTables">
                                <thead>
                                    <tr>
                                        <th>Available</th>
                                        <th>Day</th>
                                        <th>From</th>
                                        <th>End</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    
                                    @*<script>
                                        $(document).ready(function () {
                                            $each(["m", "t", "w", "th", "f", "s", "su"], function (index, value) {

                                            });
                                        });

                                    </script>*@

                                    <tr>
                                        @if (item_Avails.m != null)
                                        {
                                            @Html.CheckBox("m", (bool)item_Avails.m)
                                        }
                                        else
                                        {
                                            <td>@Html.CheckBox("m", false)</td>
                                        }
                                        @*<td>@Html.CheckBox("m",false)</td>*@
                                        <td>Monday</td>
                                        <td>@Html.TextBox("ms", item_Avails.ms, new { Type = "time", @class = "form-control" })</td>
                                        <td>@Html.TextBox("me", item_Avails.me, new { Type = "time", @class = "form-control" })</td>
                                    </tr>

                                    <tr>
                                        @if (item_Avails.t != null)
                                        {
                                            @Html.CheckBox("t", (bool)item_Avails.t)
                                        }
                                        else
                                        {
                                            <td>@Html.CheckBox("t", false)</td>
                                        }
                                        @*<td>@Html.CheckBox("t", (bool)item_Avails.t)</td>*@
                                        <td>Tuesday</td>
                                        <td>@Html.TextBox("ts", item_Avails.ts, new { Type = "time", @class = "form-control" })</td>
                                        <td>@Html.TextBox("te", item_Avails.te, new { Type = "time", @class = "form-control" })</td>
                                    </tr>
                                    <tr>
                                        @if (item_Avails.w != null)
                                        {
                                            @Html.CheckBox("w", (bool)item_Avails.w)
                                        }
                                        else
                                        {
                                            <td>@Html.CheckBox("w", false)</td>
                                        }
                                        @*<td>@Html.CheckBox("w", (bool)item_Avails.w)</td>*@
                                        <td>Wednesday</td>
                                        <td>@Html.TextBox("ws", item_Avails.ws, new { Type = "time", @class = "form-control" })</td>
                                        <td>@Html.TextBox("we", item_Avails.we, new { Type = "time", @class = "form-control" })</td>
                                    </tr>
                                    <tr>
                                        @if (item_Avails.th != null)
                                        {
                                            @Html.CheckBox("th", (bool)item_Avails.th)
                                        }
                                        else
                                        {
                                            <td>@Html.CheckBox("th", false)</td>
                                        }
                                        @*<td>@Html.CheckBox("th", (bool)item_Avails.th)</td>*@
                                        <td>Thursday</td>
                                        <td>@Html.TextBox("ths", item_Avails.ths, new { Type = "time", @class = "form-control" })</td>
                                        <td>@Html.TextBox("the", item_Avails.the, new { Type = "time", @class = "form-control" })</td>
                                    </tr>
                                    <tr>
                                        @if (item_Avails.f != null)
                                        {
                                            @Html.CheckBox("f", (bool)item_Avails.f)
                                        }
                                        else
                                        {
                                            <td>@Html.CheckBox("f", false)</td>
                                        }
                                        @*<td>@Html.CheckBox("f", (bool)item_Avails.f)</td>*@
                                        <td>Friday</td>
                                        <td>@Html.TextBox("fs", item_Avails.fs, new { Type = "time", @class = "form-control" })</td>
                                        <td>@Html.TextBox("fe", item_Avails.fe, new { Type = "time", @class = "form-control" })</td>
                                    </tr>
                                    <tr>
                                        @if (item_Avails.s != null)
                                        {
                                            @Html.CheckBox("s", (bool)item_Avails.s)
                                        }
                                        else
                                        {
                                            <td>@Html.CheckBox("s", false)</td>
                                        }
                                        @*<td>@Html.CheckBox("s", (bool)item_Avails.s)</td>*@
                                        <td>Saturday</td>
                                        <td>@Html.TextBox("ss", item_Avails.ss, new { Type = "time", @class = "form-control" })</td>
                                        <td>@Html.TextBox("se", item_Avails.se, new { Type = "time", @class = "form-control" })</td>
                                    </tr>
                                    <tr>
                                        @if (item_Avails.su != null)
                                        {
                                            @Html.CheckBox("su", (bool)item_Avails.su)
                                        }
                                        else
                                        {
                                            <td>@Html.CheckBox("su", false)</td>
                                        }
                                        @*<td>@Html.CheckBox("su", (bool)item_Avails.su)</td>*@
                                        <td>Sunday</td>
                                        <td>@Html.TextBox("sus", item_Avails.sus, new { Type = "time", @class = "form-control" })</td>
                                        <td>@Html.TextBox("sue", item_Avails.sue, new { Type = "time", @class = "form-control" })</td>
                                    </tr>
                                </tbody>
                            </table>


                        </div>

                        <div class="form-group">
                            <div class="col-md-offset-2 col-md-10">
                                <input type="submit" value="Save" class="btn btn-primary" />
                                @Html.ActionLink("Cancel", "Index", new { id = ViewBag.url }, new { @class = "btn btn-white" })
                            </div>
                        </div>
                    }

                </div>
            </div>
        </div>
    </div>
</div>

