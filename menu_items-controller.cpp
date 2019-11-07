using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Dynamic;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using NutriTrust;

namespace MyMenuV2.Controllers
{
    public class menu_itemsController : UtilitiesController
    {
        public ActionResult Index()
        {
            List<menu_items> menuItems = db.menu_items.Where(x => x.client_id == iClientID).Where(x => x.deleted == 0).ToList();
            List<default_filter_settings> defaultFilterSettings = db.default_filter_settings.Where(x => x.client_id == iClientID).Where(x => x.deleted == 0).ToList();

            dynamic dModel = new ExpandoObject();
            dModel.menuItems = menuItems;
            dModel.defaultFilterSettings = defaultFilterSettings;
            return View(dModel);
        }

      


        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            menu_items menu_items = db.menu_items.Find(id);
            if (menu_items == null)
            {
                return HttpNotFound();
            }
            return View(menu_items);
        }

        public ActionResult Create()
        {

            menu_items menuItem = new menu_items();

            if (menuItem == null)
            {
                return HttpNotFound();
            }

            dynamic dModel = new ExpandoObject();

            //Menu Item
            //menuItem = (menu_items)db.menu_items.Find(id);
            dModel.menuItem = (menu_items)menuItem;

            //menuItemsLists
            List<menu_items> menu_Items = db.menu_items.Where(x => x.client_id == iClientID).ToList();
            dModel.menu_Items = menu_Items;

            //Item Nutrition
            dModel.itemNutrition = new item_nutrition();//(item_nutrition)db.item_nutrition.Where(x => x.menu_item_id == id).Where(x => x.client_id == iClientID).FirstOrDefault();

            //Categories
            //List<int?> categoryIDs = (List<int?>)db.J_menu_items_categories.Where(x => x. == id).Select(x => x.categories_id).ToList();
            //List<category> categories = (List<category>)db.categories.Where(x => categoryIDs.Contains(x.id)).Where(x => x.client_id == iClientID).ToList();
            //dModel.categories = categories;
            dModel.categoryOptions = db.categories.Where(x => x.client_id == iClientID).ToList();
            //dModel.categoryOptions2 = new MultiSelectList(db.categories.Where(x => x.client_id == iClientID).ToList(), "id", "name", categories.Select(x => x.id).ToArray());
            //ViewBag.categoryOptions = new MultiSelectList(db.categories.Where(x => x.client_id == iClientID).ToList(), "id", "name", categories.Select(x => x.id).ToArray());

            //Default Filters
            //List<int?> defaultFilterIDs = (List<int?>)db.J_menu_items_default_filters.Where(x => x.menu_item_id == id).Select(x => x.default_filter_id).ToList();
            List<default_filters> defaultFilters = (List<default_filters>)db.default_filters.Where(x => x.type == "nutrition" || x.type == "flex" || x.type == "hd").ToList();
            dModel.defaultFilters = defaultFilters;
            //dModel.defaultFilterOptions = db.default_filters.Where(x => x.type == "nutrition" || x.type == "flex" || x.type == "hd").ToList();

            //Custom Filters
            //List<int?> customFilterIDs = (List<int?>)db.J_menu_items_custom_filters.Where(x => x.menu_item_id == id).Select(x => x.custom_filter_id).ToList();
            //List<custom_filters> customFilters = (List<custom_filters>)db.custom_filters.Where(x => customFilterIDs.Contains(x.id)).Where(x => x.client_id == iClientID).ToList();
            //dModel.customFilters = customFilters;
            dModel.customFilterOptions = db.custom_filters.Where(x => x.client_id == iClientID).ToList();

            //Gluten Filters
            //List<int?> glutenFilterIDs = (List<int?>)db.J_menu_items_default_filters.Where(x => x.menu_item_id == id).Select(x => x.default_filter_id).ToList();
            //List<default_filters> glutentFilters = (List<default_filters>)db.default_filters.Where(x => defaultFilterIDs.Contains(x.id)).Where(x => x.type == "gluten").ToList();
            //dModel.glutentFilters = glutentFilters;
            dModel.glutenFilterOptions = db.default_filters.Where(x => x.type == "gluten").ToList();

            //Allergen Filters
            //List<int?> allergenFilterIDs = db.J_menu_items_default_filters.Where(x => x.menu_item_id == id).Select(x => x.default_filter_id).ToList();
            //List<default_filters> allergenFilters = db.default_filters.Where(x => allergenFilterIDs.Contains(x.id)).Where(x => x.type == "allergen").ToList();
            //dModel.allergenFilters = allergenFilters;
            dModel.allergenFilterOptions = db.default_filters.Where(x => x.type == "allergen").ToList();

            //List<J_menu_items_default_filters> J_menu_items_default_filters = db.J_menu_items_default_filters.Where(x => x.menu_item_id == id).ToList();
            
            //dModel.J_menu_items_default_filters = J_menu_items_default_filters;
            //ViewBag.fishCC = false;
            //ViewBag.shellfishCC = false;
            //ViewBag.mollusksCC = false;
            //ViewBag.treeNutsCC = false;
            //ViewBag.WoutFish = false;
            //ViewBag.WoutShellfish = false;
            //ViewBag.WoutMollusks = false;
            //ViewBag.WoutTreenuts = false;
            //foreach (J_menu_items_default_filters item in J_menu_items_default_filters)
            //{
            //    switch (item.default_filter_id)
            //    {
            //        case 41:
            //            ViewBag.fishCC = true;
            //            break;
            //        case 36:
            //            ViewBag.shellfishCC = true;
            //            break;
            //        case 39:
            //            ViewBag.mollusksCC = true;
            //            break;
            //        case 40:
            //            ViewBag.treeNuts = true;
            //            break;
            //        case 20:
            //            ViewBag.WoutFish = true;
            //            break;
            //        case 15:
            //            ViewBag.WoutShellfish = true;
            //            break;
            //        case 18:
            //            ViewBag.WoutMollusks = true;
            //            break;
            //        case 19:
            //            ViewBag.WoutTreenuts = true;
            //            break;
            //        default:
            //            break;

            //    }
            //}

            //item_avail item_Avails = db.item_avail.Where(x => x.menu_item_id == id).FirstOrDefault();
            //if (item_Avails == null)
            //{
            //    item_avail item_Avail = new item_avail();
            //    item_Avail.created = GetTime();
            //    item_Avail.createdby = iUserID;
            //    item_Avail.deleted = 0;
            //    item_Avail.menu_item_id = menuItem.id;
            //    db.item_avail.Add(item_Avail);
            //    db.SaveChanges();
            //    dModel.item_Avails = item_Avail;
            //}
            //else
            //{
                dModel.item_Avails = new item_avail();
            //}

            //List<menu_items_igroup> menuItemIgroup = db.menu_items_igroup.Where(x => x.menu_item_id == id).ToList();
            //dModel.menuItemIgroup = menuItemIgroup;
            return View(dModel);
        }


        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create(FormCollection collection, [Bind(Include = "child_group_name,special_req,ingredient_dec,meta,name,description,s_descriptions,image,price,cmiid,child_alias,version_alias,nutrition_alias,notes")] menu_items bindMenuItem,
            [Bind(Include = "ms,me,ts,te,ws,we,ths,the,fs,fe,ss,se,sus,sue")]item_avail bindItemAvail,
            [Bind(Include = "q,aum,calories,calories_from_fat,fat,sat_fat,trans_fat,cholest,sodium,carbs,fiber,sugar,protein,fruit_veg")]item_nutrition bindItemNutrition)
        {
            if (ModelState.IsValid)
            {
                bindMenuItem.image = collection.Get("menu_item_image");
                bindMenuItem.modified = GetTime();
                bindMenuItem.modifiedby = iUserID;
                bindMenuItem.as_ingredient = bConvertCheckBoxTrueFalse(collection.Get("as_ingredient"));
                bindMenuItem.hide_on_NC = bConvertCheckBoxTrueFalse(collection.Get("hide_on_NC"));
                bindMenuItem.hide_on_MP = bConvertCheckBoxTrueFalse(collection.Get("hide_on_MP"));
                bindMenuItem.mb = bConvertCheckBoxTrueFalse(collection.Get("mb"));
                bindMenuItem.quanto = bConvertCheckBoxTrueFalse(collection.Get("quanto"));
                bindMenuItem.use_cmiid = bConvertCheckBoxTrueFalse(collection.Get("use_cmiid"));
                bool publish = bConvertCheckBoxTrueFalse(collection.Get("publishCheckBox"));
                bindMenuItem.publish = publish;
                bindMenuItem.client_id = iClientID;
                bindMenuItem.created = GetTime();
                bindMenuItem.createdby = iUserID;
                bindMenuItem.deleted = 0;
                db.menu_items.Add(bindMenuItem);

                //-----------------------ALLERGEN & CROSS-CONTACT CHECKBOXES-----------------------ALLERGEN & CROSS-CONTACT CHECKBOXES 
                Dictionary<int, string[]> allergenDictionary = new Dictionary<int, string[]>();
                //key = default_filter_id, value[0] = FormCollection name, value[1] = FormCollection type
                allergenDictionary.Add(20, new string[] { "WoutFish", "fishType" });
                allergenDictionary.Add(41, new string[] { "fishCC", "fishType" });
                allergenDictionary.Add(15, new string[] { "WoutShellfish", "shellfishType" });
                allergenDictionary.Add(36, new string[] { "shellfishCC", "shellfishType" });
                allergenDictionary.Add(18, new string[] { "WoutMollusks", "mollusksType" });
                allergenDictionary.Add(39, new string[] { "mollusksCC", "mollusksType" });
                allergenDictionary.Add(19, new string[] { "WoutTreenuts", "treeNutType" });
                allergenDictionary.Add(40, new string[] { "treeNutsCC", "treeNutType" });
                //iterate through dictionary
                foreach (KeyValuePair<int, string[]> entry in allergenDictionary)
                {
                    // do something with entry.Value or entry.Key
                    string allergenName = entry.Value[0]; //the string item
                    int allergenID = entry.Key; //the #
                    bool boxChecked = bConvertCheckBoxTrueFalse(collection.Get(allergenName)); // See if box checked
                    if (boxChecked)
                    {
                        J_menu_items_default_filters defFilter = new J_menu_items_default_filters();
                        defFilter.created = GetTime();
                        defFilter.createdby = iUserID;
                        defFilter.default_filter_id = allergenID;
                        defFilter.menu_item_id = 00000; //TODO: get menuItemID after creation of item, must have this method under creation
                        defFilter.deleted = 0;
                        defFilter.type = collection.Get(entry.Value[1]); //string in type of ___, box must be checked as in same table 
                    }
                }
                //------END-----------------END ALLERGEN & CROSS-CONTACT CHECKBOXES----------END-------------END ALLERGEN & CROSS-CONTACT CHECKBOXES 

                

                //available times for menu
                bindItemAvail.deleted = 0;
                bindItemAvail.modified = GetTime();
                bindItemAvail.modifiedby = iUserID;
                bindItemAvail.m = bConvertCheckBoxTrueFalse(collection.Get("m"));
                bindItemAvail.t = bConvertCheckBoxTrueFalse(collection.Get("t"));
                bindItemAvail.w = bConvertCheckBoxTrueFalse(collection.Get("w"));
                bindItemAvail.th = bConvertCheckBoxTrueFalse(collection.Get("th"));
                bindItemAvail.f = bConvertCheckBoxTrueFalse(collection.Get("f"));
                bindItemAvail.s = bConvertCheckBoxTrueFalse(collection.Get("s"));
                bindItemAvail.su = bConvertCheckBoxTrueFalse(collection.Get("su"));

                string childitems = collection.Get("child_Items");
                if(childitems != null)
                {
                    string[] childItemsArray = childitems.Split(',');
                    foreach(string childItem in childItemsArray)
                    {
                        int childID = Convert.ToInt32(childItem);
                        mi_parent_child child = new mi_parent_child();
                        child.parent_id = bindMenuItem.id;
                        child.child_id = childID;
                        child.created = GetTime();
                        child.createdby = iUserID;
                        child.deleted = 0;

                    }
                }


                string dfFilter = collection.Get("defaultFilters");
                if (dfFilter != null)
                {
                    string[] defaultFilterArray = dfFilter.Split(',');
                    foreach (string filter in defaultFilterArray)
                    {
                        int dfFilterId = Convert.ToInt32(filter);
                        J_menu_items_default_filters newJFilter = new J_menu_items_default_filters();
                        newJFilter.default_filter_id = dfFilterId;
                        //newJFilter.menu_item_id = menuItemID;
                        newJFilter.created = GetTime();
                        newJFilter.createdby = iUserID;
                        newJFilter.deleted = 0;
                        db.J_menu_items_default_filters.Add(newJFilter);
                    }
                }

                string cFilter = collection.Get("customFilters");
                if (cFilter != null)
                {
                    string[] cFilterArray = cFilter.Split(',');
                    foreach (string filter in cFilterArray)
                    {
                        int cfilterid = Convert.ToInt32(filter);
                        J_menu_items_custom_filters newJFilter = new J_menu_items_custom_filters();
                        newJFilter.custom_filter_id = cfilterid;
                        //newJFilter.menu_item_id = menuItemID;
                        newJFilter.created = GetTime();
                        newJFilter.createdby = iUserID;
                        newJFilter.deleted = 0;
                        db.J_menu_items_custom_filters.Add(newJFilter);
                    }
                }


                string gFilter = collection.Get("glutenFilters");
                if (gFilter != null)
                {
                    string[] defaultFilterArray = gFilter.Split(',');
                    foreach (string filter in defaultFilterArray)
                    {
                        int gFilterId = Convert.ToInt32(filter);
                        J_menu_items_default_filters newJFilter = new J_menu_items_default_filters();
                        newJFilter.default_filter_id = gFilterId;
                        //newJFilter.menu_item_id = menuItemID;
                        newJFilter.created = GetTime();
                        newJFilter.createdby = iUserID;
                        newJFilter.deleted = 0;
                        db.J_menu_items_default_filters.Add(newJFilter);
                    }
                }

                string allergenFiltercol = collection.Get("allergenFilters");
                if (allergenFiltercol != null)
                {
                    string[] allergenFilterArray = allergenFiltercol.Split(',');
                    foreach (string allergenFilter in allergenFilterArray)
                    {
                        int gFilterId = Convert.ToInt32(allergenFilter);
                        J_menu_items_default_filters newJFilter = new J_menu_items_default_filters();
                        newJFilter.default_filter_id = gFilterId;
                        //newJFilter.menu_item_id = menuItemID;
                        newJFilter.created = GetTime();
                        newJFilter.createdby = iUserID;
                        newJFilter.deleted = 0;
                        db.J_menu_items_default_filters.Add(newJFilter);
                    }
                }

                string categories = collection.Get("categories");
                if(categories != null)
                {
                    string[] categoryarr = categories.Split(',');
                    foreach(string category in categoryarr)
                    {
                        int categoryID = 0;

                    }
                }

                //db.SaveChanges();
                return RedirectToAction("Index");
            }
            return RedirectToAction("Index");
        }

        public ActionResult Edit(int? id)
        {
            menu_items menuItem = db.menu_items.Find(id);
            int iMenuID = menuItem.id;
            if (menuItem == null)
            {
                return HttpNotFound();
            }

            dynamic dModel = new ExpandoObject();

            //Menu Item
            //menuItem = (menu_items)db.menu_items.Find(id);
            dModel.menuItem = (menu_items)menuItem;

            //menuItemsLists
            List<menu_items> menu_Items = db.menu_items.Where(x => x.client_id == iClientID).Where(x => x.deleted == 0).ToList();
            dModel.menu_Items = menu_Items;

            //Item Nutrition
            dModel.itemNutrition = (item_nutrition)db.item_nutrition.Where(x => x.menu_item_id == id).Where(x => x.client_id == iClientID).FirstOrDefault();

            //Child Items
            dModel.childItemsSelected = db.mi_parent_child.Where(x => x.parent_id == iMenuID).Where(x=>x.deleted == 0).Select(x=>x.child_id).ToArray();

            //Alternate Versions 
            dModel.alternateVersionsSelected = db.mi_versions.Where(x => x.master_id == iMenuID).Where(x => x.deleted == 0).Select(x => x.slave_id).ToArray();

            //Categories
            List<int?> categoryIDs = (List<int?>)db.J_menu_items_categories.Where(x => x.menu_item_id == id).Where(x=>x.deleted==0).Select(x => x.categories_id).ToList();
            List<category> categories = (List<category>)db.categories.Where(x => categoryIDs.Contains(x.id)).Where(x => x.client_id == iClientID).ToList();
            dModel.categories = categories;
            dModel.categoryOptions = db.categories.Where(x => x.client_id == iClientID).ToList();
            dModel.categoryOptions2 = new MultiSelectList(db.categories.Where(x => x.client_id == iClientID).ToList(), "id", "name", categories.Select(x => x.id).ToArray());
            ViewBag.categoryOptions = new MultiSelectList(db.categories.Where(x => x.client_id == iClientID).ToList(), "id", "name", categories.Select(x => x.id).ToArray());

            //Default Filters
            List<int?> defaultFilterIDs = (List<int?>)db.J_menu_items_default_filters.Where(x => x.menu_item_id == id).Where(x => x.deleted == 0).Select(x => x.default_filter_id).ToList();
            List<default_filters> defaultFilters = (List<default_filters>)db.default_filters.Where(x => defaultFilterIDs.Contains(x.id)).Where(x => x.type == "nutrition" || x.type == "flex" || x.type == "hd").ToList();
            dModel.defaultFilters = defaultFilters;
            dModel.defaultFilterOptions = db.default_filters.Where(x => x.type == "nutrition" || x.type == "flex" || x.type == "hd").ToList();

            //Custom Filters
            List<int?> customFilterIDs = (List<int?>)db.J_menu_items_custom_filters.Where(x => x.menu_item_id == id).Where(x => x.deleted == 0).Select(x => x.custom_filter_id).ToList();
            List<custom_filters> customFilters = (List<custom_filters>)db.custom_filters.Where(x => customFilterIDs.Contains(x.id)).Where(x => x.client_id == iClientID).ToList();
            dModel.customFilters = customFilters;
            dModel.customFilterOptions = db.custom_filters.Where(x => x.client_id == iClientID).ToList();

            //Gluten Filters
            List<int?> glutenFilterIDs = (List<int?>)db.J_menu_items_default_filters.Where(x => x.menu_item_id == id).Where(x => x.deleted == 0).Select(x => x.default_filter_id).ToList();
            List<default_filters> glutentFilters = (List<default_filters>)db.default_filters.Where(x => defaultFilterIDs.Contains(x.id)).Where(x => x.type == "gluten").ToList();
            dModel.glutentFilters = glutentFilters;
            dModel.glutenFilterOptions = db.default_filters.Where(x => x.type == "gluten").ToList();

            //Allergen Filters
            List<int?> allergenFilterIDs = db.J_menu_items_default_filters.Where(x => x.menu_item_id == id).Where(x => x.deleted == 0).Select(x => x.default_filter_id).ToList();
            List<default_filters> allergenFilters = db.default_filters.Where(x => allergenFilterIDs.Contains(x.id)).Where(x => x.type == "allergen").ToList();
            dModel.allergenFilters = allergenFilters;
            dModel.allergenFilterOptions = db.default_filters.Where(x => x.type == "allergen").ToList();

            //Default Filters
            List<J_menu_items_default_filters> J_menu_items_default_filters = db.J_menu_items_default_filters.Where(x => x.menu_item_id == id).Where(x => x.deleted == 0).ToList();
            dModel.J_menu_items_default_filters = J_menu_items_default_filters;
            // List<J_menu_items_default_filters> allergenFilterTypes = (List<J_menu_items_default_filters>)db.J_menu_items_default_filters.Where(x => allergenFilterTypeID)
            //dModel.allergenFilterTypes = allergenFilterTypes;
                ViewBag.fishCC = false;
                ViewBag.shellfishCC = false;
                ViewBag.mollusksCC = false;
                ViewBag.treeNutsCC = false;
                ViewBag.WoutFish = false;
                ViewBag.WoutShellfish = false;
                ViewBag.WoutMollusks = false;
                ViewBag.WoutTreenuts = false;
            foreach (J_menu_items_default_filters item in J_menu_items_default_filters)
            {
                switch (item.default_filter_id)
                {
                    case 41:
                        ViewBag.fishCC = true;
                        ViewBag.Fish = item.@type;
                        break;
                    case 36:
                        ViewBag.shellfishCC = true;
                        ViewBag.ShellFish = item.@type;
                        break;
                    case 39:
                        ViewBag.mollusksCC = true;
                        ViewBag.Mollusk = item.@type;
                        break;
                    case 40:
                        ViewBag.treeNuts = true;
                        ViewBag.Tree = item.@type;
                        break;
                    case 20:
                        ViewBag.WoutFish = true;
                        ViewBag.Fish = item.@type;
                        break;
                    case 15:
                        ViewBag.WoutShellfish = true;
                        ViewBag.ShellFish = item.@type;
                        break;
                    case 18:
                        ViewBag.WoutMollusks = true;
                        ViewBag.Mollusk = item.@type;
                        break;
                    case 19:
                        ViewBag.WoutTreenuts = true;
                        ViewBag.Tree = item.@type;
                        break;
                    default:
                        break;

                }
            }
            
            item_avail item_Avails = db.item_avail.Where(x => x.menu_item_id == id).FirstOrDefault();
            if(item_Avails == null)
            {
                item_avail item_Avail = new item_avail();
                item_Avail.created = GetTime();
                item_Avail.createdby = iUserID;
                item_Avail.deleted = 0;
                item_Avail.menu_item_id = menuItem.id;
                db.item_avail.Add(item_Avail);
                db.SaveChanges();
                dModel.item_Avails = item_Avail;
            }
            else
            {
                dModel.item_Avails = item_Avails;
            }

            List<menu_items_igroup> menuItemIgroup = db.menu_items_igroup.Where(x=>x.menu_item_id == id).Where(x => x.deleted == 0).ToList();
            dModel.menuItemIgroup = menuItemIgroup;

            //Variable Ingredients DualListBox, Selected

            Dictionary<string, Dictionary<int, int[]>> dualListBoxMasterDictionary = new Dictionary<string, Dictionary<int, int[]>>();
            List<menu_items_igroup> menuGroupsList = db.menu_items_igroup.Where(x => x.menu_item_id == iMenuID).ToList();
            
            foreach(menu_items_igroup itemGroup in menuGroupsList)
            {
                List<mi_igroup_asingred> selectedMenuIds = db.mi_igroup_asingred.Where(x => x.mi_igroup_id == itemGroup.id).ToList();
                string dictionaryName = itemGroup.id.ToString();
                Dictionary<int, int[]> tempDictionary = new Dictionary<int, int[]>();
                foreach (mi_igroup_asingred miIgroup in selectedMenuIds)
                {
                    
                    tempDictionary.Add(Convert.ToInt32(miIgroup.id), new int[] { Convert.ToInt32(miIgroup.menu_item_id), Convert.ToInt32(miIgroup.sort) });
                    
                }
                dualListBoxMasterDictionary.Add(dictionaryName, tempDictionary);
            }
            dModel.VariableDictionary = dualListBoxMasterDictionary;
            //End Variable Ingredients

            return View(dModel);
        }


        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit(FormCollection collection, 
            [Bind(Include = "altv_group_name,child_group_name,name,description,s_descriptions,created_date,modification_date,price,special_req,ingredient_dec,cmiid,categories,mb,child_alias,item_name,as_ingredient,notes,meta,ingred_alias,h,avail_opt,version_alias,nutrition_alias,hide_on_NC,hide_on_MP,pending,quanto,created,createdby,modified,modifiedby,deleted,quanto_multiplier")] menu_items bindMenuItem,
            [Bind(Include ="ms,me,ts,te,ws,we,ths,the,fs,fe,ss,se,sus,sue")]item_avail bindItemAvail,
            [Bind(Include = "q,aum,calories,calories_from_fat,fat,sat_fat,trans_fat,cholest,sodium,carbs,fiber,sugar,protein,fruit_veg")]item_nutrition bindItemNutrition)
            {
            if (ModelState.IsValid)
            {
                //formcollection for dualListBox published
                string values = Request.Form["dualListbox"];
                //end dualListbox collection

                int menuItemID = Convert.ToInt32(collection.Get("menu_item_id"));

                bindMenuItem.client_id = Convert.ToInt32(collection.Get("client_id"));
                bindMenuItem.id = menuItemID;
                bindMenuItem.image = collection.Get("menu_item_image");
                bindMenuItem.modified = GetTime();
                bindMenuItem.modifiedby = iUserID;
                bindMenuItem.as_ingredient = bConvertCheckBoxTrueFalse(collection.Get("as_ingredient"));
                bindMenuItem.hide_on_NC = bConvertCheckBoxTrueFalse(collection.Get("hide_on_NC"));
                bindMenuItem.hide_on_MP = bConvertCheckBoxTrueFalse(collection.Get("hide_on_MP"));
                bindMenuItem.mb = bConvertCheckBoxTrueFalse(collection.Get("mb"));
                bindMenuItem.quanto = bConvertCheckBoxTrueFalse(collection.Get("quanto"));
                bindMenuItem.use_cmiid = bConvertCheckBoxTrueFalse(collection.Get("use_cmiid")); //(shell)
                bindMenuItem.publish = bConvertCheckBoxTrueFalse(collection.Get("publishCheckBox"));
                bindMenuItem.deleted = 0;
                db.Entry(bindMenuItem).State = EntityState.Modified;
                db.SaveChanges();

                bindItemAvail.created = Convert.ToDateTime(collection.Get("IA_created"));
                bindItemAvail.createdby = ConvertCollectionToInt(collection.Get("IA_createdby"));
                bindItemAvail.id = Convert.ToInt32(collection.Get("itemAvailID"));
                bindItemAvail.menu_item_id = Convert.ToInt32(collection.Get("IA_menu_item_id"));
                bindItemAvail.deleted = 0;
                bindItemAvail.modified = GetTime();
                bindItemAvail.modifiedby = iUserID;
                bindItemAvail.m = bConvertCheckBoxTrueFalse(collection.Get("m"));
                bindItemAvail.t = bConvertCheckBoxTrueFalse(collection.Get("t"));
                bindItemAvail.w = bConvertCheckBoxTrueFalse(collection.Get("w"));
                bindItemAvail.th = bConvertCheckBoxTrueFalse(collection.Get("th"));
                bindItemAvail.f = bConvertCheckBoxTrueFalse(collection.Get("f"));
                bindItemAvail.s = bConvertCheckBoxTrueFalse(collection.Get("s"));
                bindItemAvail.su = bConvertCheckBoxTrueFalse(collection.Get("su"));
                db.Entry(bindItemAvail).State = EntityState.Modified;
                db.SaveChanges();

                bindItemNutrition.client_id = iClientID;
                bindItemNutrition.id = Convert.ToInt32(collection.Get("itemNutritionID"));
                bindItemNutrition.created = Convert.ToDateTime(collection.Get("itemNutritionCreated"));
                bindItemNutrition.createdby = ConvertCollectionToInt(collection.Get("itemNutritionCreatedBy"));
                bindItemNutrition.menu_item_id = menuItemID;
                bindItemNutrition.modified = GetTime();
                bindItemNutrition.modifiedby = iUserID;
                db.Entry(bindItemNutrition).State = EntityState.Modified;
                db.SaveChanges();


                List<J_menu_items_default_filters> JdefaultFilters = db.J_menu_items_default_filters.Where(x=>x.menu_item_id == bindMenuItem.id).ToList();
                foreach(J_menu_items_default_filters defFilter in JdefaultFilters)
                {
                    defFilter.deleted = 1;
                }
                string test = collection.Get("defaultFilters");
                if(test != null) { 
                string[] defaultFilterArray = test.Split(',');
                foreach (string filter in defaultFilterArray)
                {
                    int ifilter = Convert.ToInt32(filter);
                    var jDefFilter = db.J_menu_items_default_filters.Where(x => x.default_filter_id == ifilter).Where(x => x.menu_item_id == menuItemID).FirstOrDefault();
                    if (jDefFilter != null)
                    {
                        jDefFilter.deleted = 0; 
                    }
                    else
                    {
                        J_menu_items_default_filters newJFilter = new J_menu_items_default_filters();
                        newJFilter.default_filter_id = ifilter;
                        newJFilter.menu_item_id = menuItemID;
                        newJFilter.created = GetTime();
                        newJFilter.createdby = iUserID;
                        newJFilter.deleted = 0;
                        db.J_menu_items_default_filters.Add(newJFilter);
                    }
                }
                }
                db.SaveChanges();

                //J_menu_items_Custom_Filters
                List<J_menu_items_custom_filters> JCustomFilter = db.J_menu_items_custom_filters.Where(x => x.menu_item_id == bindMenuItem.id).ToList();
                foreach(J_menu_items_custom_filters custFilter in JCustomFilter)
                {
                    custFilter.deleted = 1;
                }
                string custColl = collection.Get("customFilters");
                if (custColl != null)
                {
                    string[] customFilterArray = custColl.Split(',');
                    foreach (string filter in customFilterArray)
                    {
                        int ifilter = Convert.ToInt32(filter);
                        var jCustFilter = db.J_menu_items_custom_filters.Where(x => x.custom_filter_id == ifilter).Where(x => x.menu_item_id == menuItemID).FirstOrDefault();
                        if (jCustFilter != null)
                        {
                            jCustFilter.deleted = 0;
                        }
                        else
                        {
                            J_menu_items_custom_filters newJFilter = new J_menu_items_custom_filters();
                            newJFilter.custom_filter_id = ifilter;
                            newJFilter.menu_item_id = menuItemID;
                            newJFilter.created = GetTime();
                            newJFilter.createdby = iUserID;
                            newJFilter.deleted = 0;
                            db.J_menu_items_custom_filters.Add(newJFilter);
                        }
                    }
                }
                db.SaveChanges();


                //J_menu_items_Custom_Filters
                List<J_menu_items_default_filters> JdefGlutenFilter = db.J_menu_items_default_filters.Where(x => x.menu_item_id == bindMenuItem.id).Where(x=>x.type=="gluten").ToList();
                foreach (J_menu_items_default_filters glutFilter in JdefGlutenFilter)
                {
                    glutFilter.deleted = 1;
                }
                string defGlutColl = collection.Get("glutenFilters");
                if (defGlutColl != null)
                {
                    string[] glutenFilters = defGlutColl.Split(',');
                    foreach (string filter in glutenFilters)
                    {
                        int ifilter = Convert.ToInt32(filter);
                        var jGlutFilterObj = db.J_menu_items_default_filters.Where(x => x.default_filter_id == ifilter).Where(x => x.menu_item_id == menuItemID).FirstOrDefault();
                        if (jGlutFilterObj != null)
                        {
                            jGlutFilterObj.deleted = 0;
                        }
                        else
                        {
                            J_menu_items_default_filters newJFilter = new J_menu_items_default_filters();
                            newJFilter.default_filter_id = ifilter;
                            newJFilter.menu_item_id = menuItemID;
                            newJFilter.created = GetTime();
                            newJFilter.createdby = iUserID;
                            newJFilter.deleted = 0;
                            db.J_menu_items_default_filters.Add(newJFilter);
                        }
                    }
                }
                db.SaveChanges();


                //J_menu_items_Custom_Filters
                List<J_menu_items_default_filters> JdefAllergFilter = db.J_menu_items_default_filters.Where(x => x.menu_item_id == bindMenuItem.id).Where(x => x.type == "allergen").ToList();
                foreach (J_menu_items_default_filters allergenFilter in JdefAllergFilter)
                {
                    allergenFilter.deleted = 1;
                }
                string defallergenColl = collection.Get("allergenFilters");
                if (defallergenColl != null)
                {
                    string[] sallergenFilter = defallergenColl.Split(',');
                    foreach (string filter in sallergenFilter)
                    {
                        int ifilter = Convert.ToInt32(filter);
                        var jAllergenfilterObj = db.J_menu_items_default_filters.Where(x => x.default_filter_id == ifilter).Where(x => x.menu_item_id == menuItemID).FirstOrDefault();
                        if (jAllergenfilterObj != null)
                        {
                            jAllergenfilterObj.deleted = 0;
                        }
                        else
                        {
                            J_menu_items_default_filters newJFilter = new J_menu_items_default_filters();
                            newJFilter.default_filter_id = ifilter;
                            newJFilter.menu_item_id = menuItemID;
                            newJFilter.created = GetTime();
                            newJFilter.createdby = iUserID;
                            newJFilter.deleted = 0;
                            db.J_menu_items_default_filters.Add(newJFilter);
                        }
                    }
                }
                db.SaveChanges();

                bool WoutFish = bConvertCheckBoxTrueFalse(collection.Get("WoutFish"));
                bool fishCC = bConvertCheckBoxTrueFalse(collection.Get("fishCC"));
                bool WoutShellfish = bConvertCheckBoxTrueFalse(collection.Get("WoutShellfish"));
                bool shellfishCC = bConvertCheckBoxTrueFalse(collection.Get("shellfishCC"));
                bool WoutMollusks = bConvertCheckBoxTrueFalse(collection.Get("WoutMollusks"));
                bool mollusksCC = bConvertCheckBoxTrueFalse(collection.Get("mollusksCC"));
                bool WoutTreenuts = bConvertCheckBoxTrueFalse(collection.Get("WoutTreenuts"));
                bool treeNutsCC = bConvertCheckBoxTrueFalse(collection.Get("treeNutsCC"));
                bool[] checkboxarray = new bool[8];
                checkboxarray[0] = WoutFish;
                checkboxarray[1] = fishCC;
                checkboxarray[2] = WoutShellfish;
                checkboxarray[3] = shellfishCC;
                checkboxarray[4] = WoutMollusks;
                checkboxarray[5] = mollusksCC;
                checkboxarray[6] = WoutTreenuts;
                checkboxarray[7] = treeNutsCC;
                string[] checkedType = new string[8];
                checkedType[0] = "fishType";
                checkedType[1] = "fishType";
                checkedType[2] = "shellfishType";
                checkedType[3] = "shellfishType";
                checkedType[4] = "mollusksType";
                checkedType[5] = "mollusksType";
                checkedType[6] = "treeType";
                checkedType[7] = "treeType";

                int[] checkboxTableArrayNumbers = new int[] { 20,41,15,36,18,39,19,40 };
                int i = 0;
                foreach (bool value in checkboxarray)
                    {
                    if (value)
                    {
                        int currentIndex = checkboxTableArrayNumbers[i];
                     J_menu_items_default_filters filterval  = db.J_menu_items_default_filters.Where(x => x.menu_item_id == bindMenuItem.id).Where(x => x.default_filter_id == currentIndex).FirstOrDefault();
                        if(filterval != null)
                        {
                            filterval.deleted = 0;
                            if (collection.Get(checkedType[i]) != null)
                            {
                                filterval.type = collection.Get(checkedType[i]);
                            }
                        }
                        else
                        {
                            J_menu_items_default_filters newJFilter = new J_menu_items_default_filters();
                            newJFilter.default_filter_id = checkboxTableArrayNumbers[i];
                            if(collection.Get(checkedType[i]) != null)
                            {
                                filterval.type = collection.Get(checkedType[i]);
                            }
                            newJFilter.menu_item_id = menuItemID;
                            newJFilter.created = GetTime();
                            newJFilter.createdby = iUserID;
                            newJFilter.deleted = 0;
                            db.J_menu_items_default_filters.Add(newJFilter);
                        }
                    }
                    else
                    {

                    }
                    i++;
                    }
                db.SaveChanges();

                //variable items Collection
                List<menu_items_igroup> igroup = db.menu_items_igroup.Where(x => x.menu_item_id == menuItemID).AsNoTracking().ToList();
                foreach(menu_items_igroup item in igroup)
                {
                    int iID = item.id;
                    item.group_sort = Convert.ToInt32(collection.Get("group_sort" + iID));
                    item.pub = bConvertCheckBoxTrueFalse(collection.Get("VCheckbox" + iID));
                    item.name = collection.Get("Vname" + iID);
                    item.display_name = bConvertCheckBoxTrueFalse(collection.Get("display_name" + iID));
                    item.radio = bConvertCheckBoxTrueFalse(collection.Get("radio" + iID));
                    item.@default = collection.Get("default" + iID);
                    item.showon_menu = bConvertCheckBoxTrueFalse(collection.Get("showon_menu" + iID));
                    item.showon_landing = bConvertCheckBoxTrueFalse(collection.Get("showon_landing" + iID));
                    item.modified = GetTime();
                    item.modifiedby = iUserID;
                    db.Entry(item).State = EntityState.Modified;
                    db.SaveChanges();
                }

                //Child Items Dropdown
                List<mi_parent_child> parentChildList = db.mi_parent_child.Where(x => x.parent_id == menuItemID).ToList();
                foreach(mi_parent_child pcItem in parentChildList)
                {
                    pcItem.deleted = 1;
                }
                string sCollectionChildItems = collection.Get("child_Items");
                if (sCollectionChildItems != null && sCollectionChildItems != "")
                {
                    string[] sChildItemsARR = sCollectionChildItems.Split(',');
                    foreach (string child in sChildItemsARR)
                    {
                        int iChild = Convert.ToInt32(child);
                        if (parentChildList.Where(x => x.child_id == iChild).Where(x => x.parent_id == menuItemID).Any())
                        {
                            mi_parent_child ChildItem = db.mi_parent_child.Where(x => x.child_id == iChild).Where(x => x.parent_id == menuItemID).FirstOrDefault();
                            ChildItem.deleted = 0;
                            ChildItem.modified = GetTime();
                            ChildItem.modifiedby = iUserID;
                            db.Entry(ChildItem).State = EntityState.Modified;
                        }
                        else
                        {
                            mi_parent_child newChildItem = new mi_parent_child();
                            newChildItem.parent_id = menuItemID;
                            newChildItem.child_id = iChild;
                            newChildItem.created = GetTime();
                            newChildItem.createdby = iUserID;
                            newChildItem.deleted = 0;
                            db.mi_parent_child.Add(newChildItem);
                        }
                    }
                }
                db.SaveChanges();

                //Alternate Versions Dropdown
                List<mi_versions> slaves = db.mi_versions.Where(x => x.master_id == menuItemID).ToList();
                foreach (mi_versions slaveItem in slaves)
                {
                    slaveItem.deleted = 1;
                }
                string sCollectionSlaveItems = collection.Get("AlternateVersionsDropdown");
                if (sCollectionSlaveItems != null && sCollectionSlaveItems != "")
                {
                    string[] sSlaveItemsARR = sCollectionChildItems.Split(',');
                    foreach (string slave in sSlaveItemsARR)
                    {
                        int iSlave = Convert.ToInt32(slave);
                        if (slaves.Where(x => x.slave_id == iSlave).Where(x => x.master_id == menuItemID).Any())
                        {
                            mi_versions SlaveItem = db.mi_versions.Where(x => x.slave_id == iSlave).Where(x => x.master_id == menuItemID).FirstOrDefault();
                            SlaveItem.deleted = 0;
                            SlaveItem.modified = GetTime();
                            SlaveItem.modifiedby = iUserID;
                            db.Entry(SlaveItem).State = EntityState.Modified;
                        }
                        else
                        {
                            mi_versions newSlave = new mi_versions();
                            newSlave.master_id = menuItemID;
                            newSlave.slave_id = iSlave;
                            newSlave.created = GetTime();
                            newSlave.createdby = iUserID;
                            newSlave.deleted = 0;
                            db.mi_versions.Add(newSlave);
                        }
                    }
                }
                db.SaveChanges();
                //End Alternate Versions Dropdown


                //Categories Dropdown
                List<J_menu_items_categories> deleteCatList = db.J_menu_items_categories.Where(x => x.menu_item_id == menuItemID).Where(x=>x.deleted==0).ToList();
                foreach(J_menu_items_categories jmenucat in deleteCatList)
                {
                    jmenucat.deleted = 1;
                }
                string sJoinMenuCategory = collection.Get("categories");
                if(sJoinMenuCategory != null && sJoinMenuCategory != "")
                {
                    string[] sJoinMenuCategoryArr = sJoinMenuCategory.Split(',');
                    foreach(string JmenuCategory in sJoinMenuCategoryArr)
                    {
                        int iJmenuCategory = Convert.ToInt32(JmenuCategory);
                        if (db.J_menu_items_categories.Where(x => x.categories_id == iJmenuCategory).Where(x => x.menu_item_id == menuItemID).Any())//deleteCatList.Where(x => x.categories_id == iJmenuCategory).Where(x => x.menu_item_id == menuItemID).Any())
                        {
                            J_menu_items_categories jmenuCat = db.J_menu_items_categories.Where(x => x.categories_id == iJmenuCategory).Where(x => x.menu_item_id == menuItemID).FirstOrDefault();
                            jmenuCat.deleted = 0;
                            jmenuCat.modified = GetTime();
                            jmenuCat.modifiedby = iUserID;
                            db.Entry(jmenuCat).State = EntityState.Modified;
                        }
                        else
                        {
                            J_menu_items_categories jCat = new J_menu_items_categories();
                            jCat.menu_item_id = menuItemID;
                            jCat.categories_id = iJmenuCategory;
                            jCat.created = GetTime();
                            jCat.createdby = iUserID;
                            jCat.deleted = 0;
                            db.J_menu_items_categories.Add(jCat);
                        }
                    }
                }
                db.SaveChanges();


            //End Categories Dropdown

            }

            return RedirectToAction("Edit", bindMenuItem.id);
        }

        [HttpPost]
        public ActionResult PostVariableIngredients(int group_sort, bool pub, string name, bool display_name, bool radio, bool showon_menu, bool showon_landing, string @default, int menu_item_id)
        {
            menu_items_igroup newItemIgroup = new menu_items_igroup();
            newItemIgroup.created = GetTime();
            newItemIgroup.createdby = iUserID;
            newItemIgroup.deleted = 0;

            newItemIgroup.menu_item_id = menu_item_id; 
            newItemIgroup.group_sort = group_sort;
            newItemIgroup.pub = pub;
            newItemIgroup.name = name;
            newItemIgroup.display_name = display_name;
            newItemIgroup.radio = radio;
            newItemIgroup.showon_menu = showon_menu;
            newItemIgroup.showon_landing = showon_landing;
            newItemIgroup.@default = @default;
            db.menu_items_igroup.Add(newItemIgroup);
            //db.SaveChanges();
            return Json(new { success = "Added Ingredient, Refresh to View Changes" }, JsonRequestBehavior.AllowGet);
        }

        [HttpPost]
        public ActionResult DuplicateIgroup(int item_id, int group_sort, bool VCheckbox, string name, bool display_name, bool radio, string @default, bool showon_menu,bool showon_landing)
        {

            menu_items_igroup newItemIgroup = new menu_items_igroup();
            newItemIgroup.created = GetTime();
            newItemIgroup.createdby = iUserID;
            newItemIgroup.deleted = 0;

            newItemIgroup.menu_item_id = item_id;
            newItemIgroup.group_sort = group_sort;
            //newItemIgroup.pub = pub;
            newItemIgroup.name = name;
            newItemIgroup.display_name = display_name;
            newItemIgroup.radio = radio;
            newItemIgroup.showon_menu = showon_menu;
            newItemIgroup.showon_landing = showon_landing;
            newItemIgroup.@default = @default;
            db.menu_items_igroup.Add(newItemIgroup);
            //db.SaveChanges();
            return Json(new { success = "Added Ingredient, Refresh to View Changes" }, JsonRequestBehavior.AllowGet);

        }



        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            menu_items menu_items = db.menu_items.Find(id);
            if (menu_items == null)
            {
                return HttpNotFound();
            }
            return View(menu_items);
        }

        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            menu_items menu_items = db.menu_items.Find(id);
            menu_items.deleted = 1;
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        public ActionResult Categories()
        {
            List<category> categoryList = db.categories.Where(x => x.client_id == iClientID).Where(x=>x.deleted == 0).ToList();
            return View(categoryList);
        }

        public ActionResult CreateCategory()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult CreateCategory(FormCollection collection, [Bind(Include = "name, s_description")] category bindCategory)
        {
            if (ModelState.IsValid)
            {
                bindCategory.client_id = iClientID;
                bindCategory.created = GetTime();
                bindCategory.createdby = iUserID;
                db.categories.Add(bindCategory);
                db.SaveChanges();
            }

            return RedirectToAction("Categories", "menu_items");
        }

        public ActionResult EditCategory(int? id)
        {
           category category = db.categories.Find(id);
            return View(category);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult EditCategory([Bind(Include = "id,client_id,created,createdby,deleted,name,s_description")] category bindCategory)
        {
            if (ModelState.IsValid)
            {
                bindCategory.modified = GetTime();
                bindCategory.modifiedby = iUserID;
                db.Entry(bindCategory).State = EntityState.Modified;
                db.SaveChanges();
            }
            return RedirectToAction("Categories", bindCategory.id);
        }

        public ActionResult DeleteCategory(int? id)
        {
            return View(db.categories.Find(id)); 
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteCategory(int id)
        {
            category category = db.categories.Find(id);
            category.deleted = 1;
            db.SaveChanges();
            return RedirectToAction("Categories");
        }


        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}