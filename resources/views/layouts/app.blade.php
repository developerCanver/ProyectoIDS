<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="utf-8" />
    <title>IDS</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta content="Responsive bootstrap 4 admin template" name="description" />
    <meta content="Coderthemes" name="author" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <!-- App favicon -->
    <link rel="shortcut icon" href="assets/images/favicon.ico">

    <!-- Plugins css-->
    <link href="{{ asset('assets/libs/sweetalert2/sweetalert2.min.css') }}" rel="stylesheet" type="text/css" />

    <!-- App css  -->
    <link href="{{ asset('assets/css/bootstrap.min.css') }}" rel="stylesheet" type="text/css"
        id="bootstrap-stylesheet" />
    <link href="{{ asset('assets/css/icons.min.css') }}" rel="stylesheet" type="text/css" />
    <link href="{{ asset('assets/css/app.min.css') }}" rel="stylesheet" type="text/css" id="app-stylesheet" />

</head>

<body>

    <!-- Begin page -->
    <div id="wrapper">


        <!-- Topbar Start -->
        <div class="navbar-custom">
            @include('layouts.headers')
           
        </div>
        <!-- end Topbar -->
        <!-- ========== Left Sidebar Start ========== -->
                
<div class="left-side-menu">

    <div class="slimscroll-menu">

       
        <div id="sidebar-menu">
            <ul class="metismenu" id="side-menu">

                <li class="menu-title">Navigation</li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-md-speedometer"></i>
                        <span>  Dashboard  </span>
                        <span class="badge badge-info badge-pill float-right"> 3 </span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="index.html">Dashboard 1</a></li>
                        <li><a href="dashboard-2.html">Dashboard 2</a></li>
                        <li><a href="dashboard-3.html">Dashboard 3</a></li>
                    </ul>
                </li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-md-basket"></i>
                        <span> Reglas </span>
                        <span class="menu-arrow"></span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">

                        <li><a href="{{ url('/rules') }}">Exportar txt</a></li>
                        {{-- <li><a href="ui-buttons.html">Buttons</a></li>
                        <li><a href="ui-fontawesome.html">Font Awesome Icons</a></li>
                        <li><a href="ui-materialdesign.html">Material Design Icons</a></li>
                        <li><a href="ui-ionicons.html">Ion Icons</a></li>
                        <li><a href="ui-cards.html">Cards</a></li>
                        <li><a href="ui-tabs-accordions.html">Tabs &amp; Accordions</a></li>
                        <li><a href="ui-modals.html">Modals</a></li>
                        <li><a href="ui-bootstrap-ui.html">BS Elements</a></li>
                        <li><a href="ui-progressbars.html">Progress Bars</a></li>
                        <li><a href="ui-notification.html">Notification</a></li>
                        <li><a href="ui-sweet-alert.html">Sweet-Alert</a></li> --}}
                    </ul>
                </li>

                {{-- <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-ios-apps"></i>
                        <span> Components </span>
                        <span class="menu-arrow"></span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="components-grid.html">Grid</a></li>
                        <li><a href="components-portlets.html">Portlets</a></li>
                        <li><a href="components-widgets.html">Widgets</a></li>
                        <li><a href="components-nestable-list.html">Nesteble</a></li>
                        <li><a href="components-calendar.html">Calendar</a></li>
                        <li><a href="components-range-sliders.html">Range Slider</a></li>
                    </ul>
                </li> --}}

                {{-- <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-md-speedometer"></i>
                        <span>  Forms  </span>
                        <span class="badge badge-danger badge-pill float-right"> 8 </span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="forms-elements.html">General Elements</a></li>
                        <li><a href="forms-validation.html">Form Validation</a></li>
                        <li><a href="forms-advanced.html">Advanced Form</a></li>
                        <li><a href="forms-wizard.html">Form Wizard</a></li>
                        <li><a href="form-quilljs.html">Quilljs Editor</a></li>
                        <li><a href="forms-uploads.html">Multiple File Upload</a></li>
                        <li><a href="forms-image-crop.html">Image Crop</a></li>
                        <li><a href="forms-xeditable.html">X-Editable</a></li>
                    </ul>
                </li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-ios-list"></i>
                        <span> Tables </span>
                        <span class="menu-arrow"></span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="tables-basic.html">Basic Tables</a></li>
                        <li><a href="tables-datatable.html">Data Table</a></li>
                        <li><a href="tables-editable.html">Editable Table</a></li>
                        <li><a href="tables-responsive.html">Responsive Table</a></li>
                    </ul>
                </li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-md-pie"></i>
                        <span> Charts </span>
                        <span class="menu-arrow"></span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="charts-morris.html">Morris Chart</a></li>
                        <li><a href="charts-chartjs.html">Chartjs</a></li>
                        <li><a href="charts-flot.html">Flot Chart</a></li>
                        <li><a href="charts-rickshaw.html">Rickshaw Chart</a></li>
                        <li><a href="charts-peity.html">Peity Chart</a></li>
                        <li><a href="charts-c3.html">C3 Chart</a></li>
                        <li><a href="charts-other.html">Other Chart</a></li>
                    </ul>
                </li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-md-mail"></i>
                        <span> Mail </span>
                        <span class="badge badge-warning badge-pill float-right">12</span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="email-inbox.html">Inbox</a></li>
                        <li><a href="email-compose.html">Compose Mail</a></li>
                        <li><a href="email-read.html">View Mail</a></li>
                        <li><a href="email-templates.html">Email Templates</a></li>
                    </ul>
                </li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-md-map"></i>
                        <span> Maps </span>
                        <span class="menu-arrow"></span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="maps-gmap.html"> Google Map</a></li>
                        <li><a href="maps-vector.html"> Vector Map</a></li>
                    </ul>
                </li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion ion-ios-hourglass"></i>
                        <span> Layouts </span>
                        <span class="badge badge-danger badge-pill float-right">New</span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="layouts-horizontal.html">Horizontal</a></li>
                        <li><a href="layouts-light-sidebar.html">Light Sidebar</a></li>
                        <li><a href="layouts-small-sidebar.html">Small Sidebar</a></li>
                        <li><a href="layouts-sidebar-collapsed.html">Sidebar Collapsed</a></li>
                        <li><a href="layouts-unsticky.html">Unsticky Layout</a></li>
                        <li><a href="layouts-boxed.html">Boxed Layout</a></li>
                    </ul>
                </li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="ion-md-copy"></i>
                        <span> Pages </span>
                        <span class="menu-arrow"></span>
                    </a>
                    <ul class="nav-second-level" aria-expanded="false">
                        <li><a href="pages-profile.html">Profile</a></li>
                        <li><a href="pages-timeline.html">Timeline</a></li>
                        <li><a href="pages-invoice.html">Invoice</a></li>
                        <li><a href="pages-contact.html">Contact-list</a></li>
                        <li><a href="pages-login.html">Login</a></li>
                        <li><a href="pages-register.html">Register</a></li>
                        <li><a href="pages-recoverpw.html">Recover Password</a></li>
                        <li><a href="pages-lock-screen.html">Lock Screen</a></li>
                        <li><a href="pages-blank.html">Blank Page</a></li>
                        <li><a href="pages-404.html">404 Error</a></li>
                        <li><a href="pages-404_alt.html">404 alt</a></li>
                        <li><a href="pages-500.html">500 Error</a></li>
                    </ul>
                </li>

                <li>
                    <a href="javascript: void(0);" class="waves-effect">
                        <i class="mdi mdi-share-variant"></i>
                        <span> Multi Level </span>
                        <span class="menu-arrow"></span>
                    </a>
                    <ul class="nav-second-level nav" aria-expanded="false">
                        <li>
                            <a href="javascript: void(0);">Level 1.1</a>
                        </li>
                        <li>
                            <a href="javascript: void(0);" aria-expanded="false">Level 1.2
                                    <span class="menu-arrow"></span>
                                </a>
                            <ul class="nav-third-level nav" aria-expanded="false">
                                <li>
                                    <a href="javascript: void(0);">Level 2.1</a>
                                </li>
                                <li>
                                    <a href="javascript: void(0);">Level 2.2</a>
                                </li>
                            </ul>
                        </li>
                    </ul>
                </li> --}}
            </ul>
        </div>
        <div class="clearfix"></div>
    </div>
</div>
        <!-- Left Sidebar End -->

        <!-- ============================================================== -->
        <!-- Start Page Content here -->
        <!-- ============================================================== -->

        <div class="content-page">
            <div class="content">

                @yield('content')
                <!-- end container-fluid -->

            </div>
            <!-- end content -->



            <!-- Footer Start -->
            <footer class="footer">
                <div class="container-fluid">
                    <div class="row">
                        <div class="col-md-12">
                            2015 - 2020 &copy; Velonic theme by <a href="">Coderthemes</a>
                        </div>
                    </div>
                </div>
            </footer>
            <!-- end Footer -->

        </div>

        <!-- ============================================================== -->
        <!-- End Page content -->
        <!-- ============================================================== -->

    </div>
    <!-- END wrapper -->


    <!-- Right Sidebar -->
    <div class="right-bar">
        <div class="rightbar-title">
            <a href="javascript:void(0);" class="right-bar-toggle float-right">
                <i class="mdi mdi-close"></i>
            </a>
            <h4 class="font-17 m-0 text-white">Theme Customizer</h4>
        </div>
        <div class="slimscroll-menu">

            <div class="p-4">
                <div class="alert alert-warning" role="alert">
                    <strong>Customize </strong> the overall color scheme, layout, etc.
                </div>
                <div class="mb-2">
                    <img src="assets/images/layouts/light.png" class="img-fluid img-thumbnail" alt="">
                </div>
                <div class="custom-control custom-switch mb-3">
                    <input type="checkbox" class="custom-control-input theme-choice" id="light-mode-switch" checked />
                    <label class="custom-control-label" for="light-mode-switch">Light Mode</label>
                </div>

                <div class="mb-2">
                    <img src="assets/images/layouts/dark.png" class="img-fluid img-thumbnail" alt="">
                </div>
                <div class="custom-control custom-switch mb-3">
                    <input type="checkbox" class="custom-control-input theme-choice" id="dark-mode-switch"
                        data-bsStyle="assets/css/bootstrap-dark.min.css" data-appStyle="assets/css/app-dark.min.css" />
                    <label class="custom-control-label" for="dark-mode-switch">Dark Mode</label>
                </div>

                <div class="mb-2">
                    <img src="assets/images/layouts/rtl.png" class="img-fluid img-thumbnail" alt="">
                </div>
                <div class="custom-control custom-switch mb-5">
                    <input type="checkbox" class="custom-control-input theme-choice" id="rtl-mode-switch"
                        data-appStyle="assets/css/app-rtl.min.css" />
                    <label class="custom-control-label" for="rtl-mode-switch">RTL Mode</label>
                </div>

            </div>
        </div> <!-- end slimscroll-menu-->
    </div>
    <!-- Vendor js -->
    <script src="{{ asset('assets/js/vendor.min.js') }}"></script>

    <script src="{{ asset('assets/libs/moment/moment.min.js') }}"></script>
    <script src="{{ asset('assets/libs/jquery-scrollto/jquery.scrollTo.min.js') }}"></script>
    <script src="{{ asset('assets/libs/sweetalert2/sweetalert2.min.js') }}"></script>

    <!-- Chat app -->
    <!-- <script src="{{ asset('assets/js/pages/jquery.chat.js') }}"></script>

        <!-- Todo app -->
    <script src="{{ asset('assets/js/pages/jquery.todo.js') }}"></script>

    <!--Morris Chart-->
    <script src="{{ asset('assets/libs/morris-js/morris.min.js') }}"></script>
    <script src="{{ asset('assets/libs/raphael/raphael.min.js') }}"></script>

    <!-- Sparkline charts -->
    <script src="{{ asset('assets/libs/jquery-sparkline/jquery.sparkline.min.js') }}"></script>

    <!-- Dashboard init JS -->
    <script src="{{ asset('assets/js/pages/dashboard.init.js') }}"></script>

    <!-- App js -->
    <script src="{{ asset('assets/js/app.min.js') }}"></script>

</body>

</html>
